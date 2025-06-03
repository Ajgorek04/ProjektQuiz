#include "quizmanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <random>
#include <algorithm>

/**
 * @brief Konstruktor domyślny – ustawia indeks aktualnego pytania na 0.
 */
QuizManager::QuizManager()
    : currentQuestionIndex(0) {}

/**
 * @brief Miesza kolejność pytań za pomocą algorytmu Fishera-Yatesa.
 */
void QuizManager::shuffleQuestions() {
    std::random_device rd;
    std::mt19937 g(rd()); // Generator liczb losowych
    std::shuffle(questions.begin(), questions.end(), g); // Mieszanie
    currentQuestionIndex = 0; // Reset indeksu
}

/**
 * @brief Sprawdza, czy są jeszcze pytania do zadania.
 */
bool QuizManager::hasMoreQuestions() const {
    return currentQuestionIndex < questions.size();
}

/**
 * @brief Zwraca aktualne pytanie.
 */
const Question& QuizManager::currentQuestion() const {
    return questions[currentQuestionIndex];
}

/**
 * @brief Przechodzi do kolejnego pytania, jeśli są jeszcze jakieś.
 */
void QuizManager::nextQuestion() {
    if (hasMoreQuestions()) {
        currentQuestionIndex++;
    }
}

/**
 * @brief Sprawdza poprawność odpowiedzi.
 * @param answer Litera odpowiedzi użytkownika (A, B, C, D).
 */
bool QuizManager::checkAnswer(QChar answer) const {
    return answer == currentQuestion().getCorrectAnswer();
}

/**
 * @brief Ładuje pytania z pliku CSV bez filtrowania.
 * @param filePath Ścieżka do pliku.
 */
bool QuizManager::loadQuestions(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku z pytaniami:" << filePath;
        return false;
    }

    QTextStream in(&file);
    questions.clear(); // Czyścimy stare pytania

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(';');
        if (parts.size() < 7) continue; // Oczekiwane: pytanie, 4 odp., poprawna, kategoria

        // Tworzenie pytania i dodanie do listy
        Question q(parts[0], {parts[1], parts[2], parts[3], parts[4]}, parts[5][0].toUpper(), parts[6]);
        questions.append(q);
    }

    file.close();
    currentQuestionIndex = 0;
    return !questions.isEmpty();
}

/**
 * @brief Ładuje pytania z pliku CSV, filtrując je wg podanych kategorii.
 * @param filePath Ścieżka do pliku.
 * @param categories Lista wybranych kategorii.
 */
bool QuizManager::loadQuestions(const QString& filePath, const QStringList& categories) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku z pytaniami:" << filePath;
        return false;
    }

    QTextStream in(&file);
    QVector<Question> allQuestions;

    // Parsowanie wszystkich pytań
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(';');
        if (parts.size() < 7) continue;

        Question q(parts[0], {parts[1], parts[2], parts[3], parts[4]}, parts[5][0].toUpper(), parts[6]);
        allQuestions.append(q);
    }

    file.close();
    questions.clear();

    // Jeśli brak filtrów – wczytaj wszystkie
    if (categories.isEmpty()) {
        questions = allQuestions;
    } else {
        // W przeciwnym razie – filtruj po kategoriach
        for (const Question& q : allQuestions) {
            if (categories.contains(q.getCategory())) {
                questions.append(q);
            }
        }
    }

    currentQuestionIndex = 0;
    return !questions.isEmpty();
}
