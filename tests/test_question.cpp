#include <QtTest>
#include "../src/question.h"

class TestQuestion : public QObject {
    Q_OBJECT

private slots:
    void test_getters();
};

void TestQuestion::test_getters()
{
    Question q("Stolica Polski?", {"Warszawa", "Kraków", "Gdańsk", "Wrocław"}, 'A', "Geografia");

    QCOMPARE(q.getText(), QString("Stolica Polski?"));
    QCOMPARE(q.getAnswers().size(), 4);
    QCOMPARE(q.getCorrectAnswer(), QChar('A'));
    QCOMPARE(q.getCategory(), QString("Geografia"));
}

QTEST_MAIN(TestQuestion)
#include "test_question.moc"
