#include "question.h"

Question::Question(const QString& text, const QStringList& answers, const QChar& correctAnswer, const QString& category)
    : text(text), answers(answers), correctAnswer(correctAnswer), category(category) {}

QString Question::getText() const {
    return text;
}

QStringList Question::getAnswers() const {
    return answers;
}

QChar Question::getCorrectAnswer() const {
    return correctAnswer;
}

QString Question::getCategory() const {
    return category;
}
