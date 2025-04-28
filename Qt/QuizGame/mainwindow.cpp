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
    QFile file("categories.csv");
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
    if (quizManager.loadQuestions("questions.csv")) {
        quizManager.shuffleQuestions();
        showQuestion();
    } else {
        qDebug() << "Błąd podczas ładowania pytań";
    }
}

void MainWindow::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(2);
    loadQuestions();
}


void MainWindow::on_button_next_clicked()
{
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

