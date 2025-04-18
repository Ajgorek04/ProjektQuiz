#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QStringList>
class Question
{
public:
    Question();
    Question(const QString& text, const QStringList& answers, const QChar& correctAnswer, const QString& category);

    QString getText() const;
    QStringList getAnswers() const;
    QChar getCorrectAnswer() const;
    QString getCategory() const;

private:
    QString text;
    QStringList answers;
    QChar correctAnswer;
    QString category;
};


#endif // QUESTION_H
