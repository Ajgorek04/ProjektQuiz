#include "question.h"

/**
 * @brief Konstruktor parametryczny klasy Question.
 * Inicjalizuje wszystkie pola pytania na podstawie przekazanych argumentów.
 * 
 * @param text Treść pytania.
 * @param answers Lista możliwych odpowiedzi.
 * @param correctAnswer Poprawna odpowiedź ('A', 'B', 'C' lub 'D').
 * @param category Kategoria pytania.
 */
Question::Question(const QString& text, const QStringList& answers, const QChar& correctAnswer, const QString& category)
    : text(text), answers(answers), correctAnswer(correctAnswer), category(category)
{
    // Inicjalizacja zakończona – wszystkie pola przypisane.
}

/**
 * @brief Zwraca treść pytania.
 * @return Tekst pytania jako QString.
 */
QString Question::getText() const {
    return text;
}

/**
 * @brief Zwraca listę wszystkich odpowiedzi.
 * @return QStringList z odpowiedziami A–D.
 */
QStringList Question::getAnswers() const {
    return answers;
}

/**
 * @brief Zwraca poprawną odpowiedź.
 * @return QChar reprezentujący poprawną odpowiedź ('A'–'D').
 */
QChar Question::getCorrectAnswer() const {
    return correctAnswer;
}

/**
 * @brief Zwraca kategorię pytania.
 * @return Kategoria jako QString.
 */
QString Question::getCategory() const {
    return category;
}
