#include "quizmanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <random>
#include <algorithm>

QuizManager::QuizManager()
    : currentQuestionIndex(0) {}

void QuizManager::shuffleQuestions() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(questions.begin(), questions.end(), g);
    currentQuestionIndex = 0;
}

bool QuizManager::hasMoreQuestions() const {
    return currentQuestionIndex < questions.size();
}

const Question& QuizManager::currentQuestion() const {
    return questions[currentQuestionIndex];
}

void QuizManager::nextQuestion() {
    if (hasMoreQuestions()) {
        currentQuestionIndex++;
    }
}

bool QuizManager::checkAnswer(QChar answer) const {
    return answer == currentQuestion().getCorrectAnswer();
}

bool QuizManager::loadQuestions(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku z pytaniami:" << filePath;
        return false;
    }

    QTextStream in(&file);
    questions.clear();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(';');
        if (parts.size() < 7) continue;

        Question q(parts[0], {parts[1], parts[2], parts[3], parts[4]}, parts[5][0].toUpper(), parts[6]);
        questions.append(q);
    }

    file.close();
    currentQuestionIndex = 0;
    return !questions.isEmpty();
}
