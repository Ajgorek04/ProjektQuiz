#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "question.h"
#include <QVector>

class QuizManager {
public:
    QuizManager();
    bool loadQuestions(const QString& filePath);
    void shuffleQuestions();
    bool hasMoreQuestions() const;
    const Question& currentQuestion() const;
    void nextQuestion();
    bool checkAnswer(QChar answer) const;

private:
    QVector<Question> questions;
    int currentQuestionIndex;
};

#endif // QUIZMANAGER_H
