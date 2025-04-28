#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "question.h"
#include <QVector>

/**
 * @brief Klasa zarządzająca pytaniami w quizie.
 */
class QuizManager {
public:
    /**
     * @brief Konstruktor domyślny.
     */
    QuizManager();

    /**
     * @brief Ładuje pytania z pliku CSV.
     * @param filePath Ścieżka do pliku z pytaniami.
     * @return true jeśli udało się załadować pytania, false w przeciwnym razie.
     */
    bool loadQuestions(const QString& filePath);

    /**
     * @brief Tasuje załadowane pytania w losowej kolejności.
     */
    void shuffleQuestions();

    /**
     * @brief Sprawdza, czy są jeszcze dostępne pytania.
     * @return true jeśli są dostępne pytania, false jeśli nie.
     */
    bool hasMoreQuestions() const;

    /**
     * @brief Zwraca aktualne pytanie.
     * @return Aktualne pytanie.
     */
    const Question& currentQuestion() const;

    /**
     * @brief Przechodzi do następnego pytania.
     */
    void nextQuestion();

    /**
     * @brief Sprawdza poprawność odpowiedzi.
     * @param answer Wybrana odpowiedź.
     * @return true jeśli odpowiedź jest poprawna, false w przeciwnym razie.
     */
    bool checkAnswer(QChar answer) const;

private:
    QVector<Question> questions; ///< Lista pytań.
    int currentQuestionIndex; ///< Indeks aktualnego pytania.
};

#endif // QUIZMANAGER_H
