#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QPalette>
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "../../src/question.h"
#include <algorithm>
#include <random>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Quiz Game");
    ui->stackedWidget->setCurrentIndex(0);

    QPixmap background(":/background/images/background.jpg");
        qDebug();
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(background));
        this->setAutoFillBackground(true);
        this->setPalette(palette);
}
MainWindow::~MainWindow()
{
    delete ui;
}

// START GRY
void MainWindow::on_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_category_clicked()
{
    loadCategories();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::loadCategories()
{
    QFile file("F:/Coding/ProjektQuiz/Qt/QuizGame/categories.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku categories.csv";
        return;
    }

    QTextStream in(&file);
    ui->listWidget_category->clear();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            ui->listWidget_category->addItem(line);
        }
    }

    file.close();
}

void MainWindow::loadQuestions()
{
    if (quizManager.loadQuestions("F:/Coding/ProjektQuiz/Qt/QuizGame/questions.csv")) {
        quizManager.shuffleQuestions();
        showQuestion();
    } else {
        qDebug() << "Błąd podczas ładowania pytań";
    }
}

void MainWindow::on_back_button_clicked()
{
    correctAnswers = 0;
    totalRounds = 0;
    currentRound = 0;
    totalPlayers = 1;  // Resetuj liczbę graczy
    currentPlayer = 1;
    playerScores.clear(); // Opróżnij tablicę wyników graczy
    ui->stackedWidget->setCurrentIndex(0); // Powrót do ekranu głównego
}


void MainWindow::on_back_button2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_rules_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_back_button3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Powrot z wyboru trybu gry
void MainWindow::on_back_button4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_tryb_gry1_clicked()
{
    // Resetujemy zmienne odpowiedzialne za tryb wieloosobowy
    totalPlayers = 1; // tylko 1 gracz
    currentPlayer = 1;
    correctAnswers = 0;

    ui->stackedWidget->setCurrentIndex(5); // Strona pytań w trybie jednoosobowym
    loadQuestions();
}


void MainWindow::on_button_next_clicked()
{
    if (totalPlayers > 1) {
        // Przełącz gracza w trybie wieloosobowym
        currentPlayer++;
        if (currentPlayer > totalPlayers) {
            currentPlayer = 1;
            currentRound++;
        }
    } else {
        // W trybie jednoosobowym nie zmienia się gracz
        currentRound++;
    }

    if (currentRound > totalRounds) {
        // Koniec gry
        ui->stackedWidget->setCurrentWidget(ui->page_result);
        ui->label_result->setText(QString("Koniec gry!\nTwój wynik: %1 / %2").arg(correctAnswers).arg(totalRounds * totalPlayers));
        return;
    }

    // Przejście do kolejnego pytania
    quizManager.nextQuestion();
    showQuestion();
}


void MainWindow::on_button_answerA_clicked()
{
    checkAnswer('A');
}

void MainWindow::on_button_answerB_clicked()
{
    checkAnswer('B');
}

void MainWindow::on_button_answerC_clicked()
{
    checkAnswer('C');
}

void MainWindow::on_button_answerD_clicked()
{
    checkAnswer('D');
}


void MainWindow::checkAnswer(QChar answer)
{
    if (quizManager.checkAnswer(answer)) {
        ui->label_feedback->setText("✅ Dobra odpowiedź!");
        correctAnswers++;
    } else {
        ui->label_feedback->setText("❌ Zła odpowiedź! Poprawna: " + QString(quizManager.currentQuestion().getCorrectAnswer()));
    }

    ui->button_next->setEnabled(true);
    ui->button_answerA->setEnabled(false);
    ui->button_answerB->setEnabled(false);
    ui->button_answerC->setEnabled(false);
    ui->button_answerD->setEnabled(false);
}


void MainWindow::showQuestion()
{
    ui->label_current_player->setText(QString("Gracz %1 odpowiada").arg(currentPlayer));
    if (!quizManager.hasMoreQuestions()) {
        ui->label_question->setText("Koniec quizu!");
        ui->button_answerA->setEnabled(false);
        ui->button_answerB->setEnabled(false);
        ui->button_answerC->setEnabled(false);
        ui->button_answerD->setEnabled(false);
        ui->button_next->setEnabled(false);
        ui->label_category->clear();
        return;
    }

    const Question& q = quizManager.currentQuestion();

    ui->label_question->setText(q.getText());
    ui->label_category->setText("Kategoria: " + q.getCategory());

    QStringList answers = q.getAnswers();
    ui->button_answerA->setText("A: " + answers[0]);
    ui->button_answerB->setText("B: " + answers[1]);
    ui->button_answerC->setText("C: " + answers[2]);
    ui->button_answerD->setText("D: " + answers[3]);

    ui->button_answerA->setEnabled(true);
    ui->button_answerB->setEnabled(true);
    ui->button_answerC->setEnabled(true);
    ui->button_answerD->setEnabled(true);
    ui->button_next->setEnabled(false);
    ui->label_feedback->clear();
}


void MainWindow::on_button_back_to_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_start_rounds_clicked()
{
    bool ok;
    int rounds = ui->lineEdit_rounds->text().toInt(&ok);

    if (ok && rounds > 0) {
        totalRounds = rounds;
        currentRound = 1; // zaczynamy od pierwszej rundy
        ui->stackedWidget->setCurrentIndex(2); // przejdź na stronę quizu (jeśli quiz jest na stronie 2)
        loadQuestions();
    } else {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawną liczbę rund!");
    }
}


void MainWindow::on_exit_2_clicked()
{
    QApplication::quit();
}


void MainWindow::on_button_return_to_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // powrót na stronę główną
    totalRounds = 0;
    currentRound = 0;
    correctAnswers = 0;
}


void MainWindow::on_button_return_to_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // powrót na stronę główną
}


void MainWindow::on_tryb_gry_multiplayer_clicked()
{
    // Resetujemy zmienne odpowiedzialne za tryb jednoosobowy
    totalPlayers = 0; // Ustawiamy na 0, będzie zaktualizowane po wprowadzeniu liczby graczy
    currentPlayer = 1;
    correctAnswers = 0;

    ui->stackedWidget->setCurrentIndex(7); // Strona wyboru trybu wieloosobowego
}


void MainWindow::on_button_start_multiplayer_clicked()
{
    bool okRounds, okPlayers;
    int rounds = ui->lineEdit_multi_rounds->text().toInt(&okRounds);
    int players = ui->lineEdit_players_count->text().toInt(&okPlayers);

    if (okRounds && rounds > 0 && okPlayers && players > 0) {
        totalRounds = rounds;
        totalPlayers = players; // Zmieniamy liczbę graczy na podaną przez użytkownika
        currentRound = 1;
        currentPlayer = 1;
        correctAnswers = 0;

        loadQuestions();
        ui->stackedWidget->setCurrentIndex(2); // Strona pytań
        showQuestion();
    } else {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawną liczbę rund i graczy!");
    }
}
