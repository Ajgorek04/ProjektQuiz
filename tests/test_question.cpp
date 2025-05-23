#include <QtTest>
#include "../src/question.h"

// Klasa testowa dziedzicząca po QObject, zawierająca testy jednostkowe klasy Question
class TestQuestion : public QObject {
    Q_OBJECT

private slots:
    // Testuje poprawność getterów klasy Question
    void test_getters();

    // Testuje, czy zawartość odpowiedzi jest zgodna z tą przekazaną w konstruktorze
    void test_answersContent();

    // Sprawdza, czy poprawna odpowiedź mieści się w zakresie dostępnych opcji (A, B, C, ...)
    void test_correctAnswerValid();

    // Sprawdza, czy kategoria pytania nie jest pusta
    void test_categoryNotEmpty();

    // Sprawdza zachowanie klasy Question przy pustych danych wejściowych
    void test_emptyFields();

    // Sprawdza, czy konstruktor poprawnie ustawia wszystkie pola klasy
    void test_constructor();

    // UWAGA: test_isAnswerCorrect usunięty, jeśli metoda nie istnieje w klasie Question
};

void TestQuestion::test_getters()
{
    // Tworzymy pytanie z kompletem danych
    Question q("Stolica Polski?", {"Warszawa", "Kraków", "Gdańsk", "Wrocław"}, 'A', "Geografia");

    // Sprawdzamy, czy getText() zwraca poprawną treść pytania
    QCOMPARE(q.getText(), QString("Stolica Polski?"));

    // Sprawdzamy, czy getAnswers() zwraca listę 4 odpowiedzi
    QCOMPARE(q.getAnswers().size(), 4);

    // Sprawdzamy, czy poprawna odpowiedź to 'A'
    QCOMPARE(q.getCorrectAnswer(), QChar('A'));

    // Sprawdzamy, czy kategoria to "Geografia"
    QCOMPARE(q.getCategory(), QString("Geografia"));
}

void TestQuestion::test_answersContent()
{
    // Tworzymy pytanie z konkretnymi odpowiedziami
    Question q("Pytanie?", {"Odp1", "Odp2", "Odp3", "Odp4"}, 'B', "Kategoria");

    // Sprawdzamy, czy każda odpowiedź ma właściwą treść
    QCOMPARE(q.getAnswers().at(0), QString("Odp1"));
    QCOMPARE(q.getAnswers().at(1), QString("Odp2"));
    QCOMPARE(q.getAnswers().at(2), QString("Odp3"));
    QCOMPARE(q.getAnswers().at(3), QString("Odp4"));
}

void TestQuestion::test_correctAnswerValid()
{
    // Tworzymy pytanie z poprawną odpowiedzią 'A'
    Question q("Stolica Polski?", {"Warszawa", "Kraków", "Gdańsk", "Wrocław"}, 'A', "Geografia");

    // Konwertujemy poprawną odpowiedź do chara i sprawdzamy, czy mieści się w zakresie możliwych
    char correct = q.getCorrectAnswer().toLatin1();
    QVERIFY(correct >= 'A' && correct < 'A' + q.getAnswers().size());
}

void TestQuestion::test_categoryNotEmpty()
{
    // Tworzymy pytanie z kategorią "Historia"
    Question q("Pytanie?", {"Tak", "Nie"}, 'A', "Historia");

    // Sprawdzamy, czy kategoria nie jest pusta
    QVERIFY(!q.getCategory().isEmpty());
}

void TestQuestion::test_emptyFields()
{
    // Tworzymy pytanie z pustymi polami
    Question q("", {}, 'A', "");

    // Sprawdzamy, czy treść pytania to pusty string
    QCOMPARE(q.getText(), QString(""));

    // Sprawdzamy, czy lista odpowiedzi jest pusta
    QCOMPARE(q.getAnswers().size(), 0);

    // Sprawdzamy, czy kategoria to pusty string
    QCOMPARE(q.getCategory(), QString(""));

    // Sprawdzamy, czy poprawna odpowiedź to 'A', mimo braku odpowiedzi
    QCOMPARE(q.getCorrectAnswer(), QChar('A'));
}

void TestQuestion::test_constructor()
{
    // Tworzymy pytanie z kompletem danych
    Question q1("Pytanie?", {"A", "B", "C"}, 'B', "Kategoria");

    // Sprawdzamy, czy konstruktor poprawnie ustawił wszystkie pola
    QCOMPARE(q1.getText(), QString("Pytanie?"));
    QCOMPARE(q1.getCategory(), QString("Kategoria"));
    QCOMPARE(q1.getCorrectAnswer(), QChar('B'));
    QCOMPARE(q1.getAnswers().size(), 3);
}

// Główna funkcja uruchamiająca testy
QTEST_MAIN(TestQuestion)
#include "test_question.moc"
