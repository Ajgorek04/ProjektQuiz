#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "question.h"
#include <QVector>
#include <QStringList>

/**
 * @brief Klasa zarządzająca logiką quizu: ładowaniem pytań, nawigacją oraz oceną odpowiedzi.
 */
class QuizManager {
public:
    /**
     * @brief Konstruktor domyślny, inicjalizuje indeks pytania.
     */
    QuizManager();

    /**
     * @brief Ładuje wszystkie pytania z pliku CSV.
     * @param filePath Ścieżka do pliku CSV z pytaniami.
     * @return true jeśli udało się załadować pytania, false w przeciwnym razie.
     */
    bool loadQuestions(const QString& filePath);

    /**
     * @brief Ładuje pytania z pliku CSV, filtrując po kategoriach.
     * @param filePath Ścieżka do pliku.
     * @param categories Lista kategorii, które mają być wczytane.
     * @return true jeśli udało się załadować przynajmniej jedno pytanie.
     */
    bool loadQuestions(const QString& filePath, const QStringList& categories);

    /**
     * @brief Miesza kolejność pytań.
     */
    void shuffleQuestions();

    /**
     * @brief Sprawdza, czy są jeszcze dostępne pytania.
     * @return true jeśli są jeszcze pytania, false jeśli koniec.
     */
    bool hasMoreQuestions() const;

    /**
     * @brief Zwraca aktualnie wyświetlane pytanie.
     * @return Referencja do aktualnego pytania.
     */
    const Question& currentQuestion() const;

    /**
     * @brief Przechodzi do następnego pytania.
     */
    void nextQuestion();

    /**
     * @brief Sprawdza, czy odpowiedź użytkownika jest poprawna.
     * @param answer Litera odpowiedzi wybranej przez użytkownika.
     * @return true jeśli odpowiedź jest poprawna.
     */
    bool checkAnswer(QChar answer) const;

private:
    QVector<Question> questions;        ///< Lista wszystkich pytań.
    int currentQuestionIndex;           ///< Indeks aktualnego pytania.
};

#endif // QUIZMANAGER_H
