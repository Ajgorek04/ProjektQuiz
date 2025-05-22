#include <QtTest>
#include "../src/question.h"

class TestQuestion : public QObject {
    Q_OBJECT

private slots:
    void test_getters();
    void test_answersContent();
    void test_correctAnswerValid();
    void test_categoryNotEmpty();
    void test_emptyFields();
    void test_constructor();
    // void test_isAnswerCorrect(); // usuń jeśli brak metody w klasie Question
};

void TestQuestion::test_getters()
{
    Question q("Stolica Polski?", {"Warszawa", "Kraków", "Gdańsk", "Wrocław"}, 'A', "Geografia");

    QCOMPARE(q.getText(), QString("Stolica Polski?"));
    QCOMPARE(q.getAnswers().size(), 4);
    QCOMPARE(q.getCorrectAnswer(), QChar('A'));
    QCOMPARE(q.getCategory(), QString("Geografia"));
}

void TestQuestion::test_answersContent()
{
    Question q("Pytanie?", {"Odp1", "Odp2", "Odp3", "Odp4"}, 'B', "Kategoria");

    QCOMPARE(q.getAnswers().at(0), QString("Odp1"));
    QCOMPARE(q.getAnswers().at(1), QString("Odp2"));
    QCOMPARE(q.getAnswers().at(2), QString("Odp3"));
    QCOMPARE(q.getAnswers().at(3), QString("Odp4"));
}

void TestQuestion::test_correctAnswerValid()
{
    Question q("Stolica Polski?", {"Warszawa", "Kraków", "Gdańsk", "Wrocław"}, 'A', "Geografia");
    
    char correct = q.getCorrectAnswer().toLatin1();
    QVERIFY(correct >= 'A' && correct < 'A' + q.getAnswers().size());
}

void TestQuestion::test_categoryNotEmpty()
{
    Question q("Pytanie?", {"Tak", "Nie"}, 'A', "Historia");
    QVERIFY(!q.getCategory().isEmpty());
}

void TestQuestion::test_emptyFields()
{
    Question q("", {}, 'A', "");

    QCOMPARE(q.getText(), QString(""));
    QCOMPARE(q.getAnswers().size(), 0);
    QCOMPARE(q.getCategory(), QString(""));
    QCOMPARE(q.getCorrectAnswer(), QChar('A'));
}

void TestQuestion::test_constructor()
{
    Question q1("Pytanie?", {"A", "B", "C"}, 'B', "Kategoria");
    QCOMPARE(q1.getText(), QString("Pytanie?"));
    QCOMPARE(q1.getCategory(), QString("Kategoria"));
    QCOMPARE(q1.getCorrectAnswer(), QChar('B'));
    QCOMPARE(q1.getAnswers().size(), 3);
}

QTEST_MAIN(TestQuestion)
#include "test_question.moc"
