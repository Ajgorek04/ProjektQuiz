#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QStringList>

/**
 * @brief Klasa reprezentująca pojedyncze pytanie w quizie.
 */
class Question
{
public:
    /**
     * @brief Domyślny konstruktor klasy Question.
     */
    Question();

    /**
     * @brief Konstruktor tworzący pytanie z podanym tekstem, odpowiedziami, poprawną odpowiedzią i kategorią.
     * @param text Treść pytania.
     * @param answers Lista możliwych odpowiedzi.
     * @param correctAnswer Poprawna odpowiedź ('A', 'B', 'C' lub 'D').
     * @param category Kategoria pytania.
     */
    Question(const QString& text, const QStringList& answers, const QChar& correctAnswer, const QString& category);

    /**
     * @brief Zwraca treść pytania.
     * @return Tekst pytania.
     */
    QString getText() const;

    /**
     * @brief Zwraca listę możliwych odpowiedzi.
     * @return Lista odpowiedzi.
     */
    QStringList getAnswers() const;

    /**
     * @brief Zwraca poprawną odpowiedź.
     * @return Poprawna odpowiedź jako znak.
     */
    QChar getCorrectAnswer() const;

    /**
     * @brief Zwraca kategorię pytania.
     * @return Kategoria pytania.
     */
    QString getCategory() const;

private:
    QString text; ///< Treść pytania.
    QStringList answers; ///< Lista możliwych odpowiedzi.
    QChar correctAnswer; ///< Poprawna odpowiedź.
    QString category; ///< Kategoria pytania.
};

#endif // QUESTION_H
