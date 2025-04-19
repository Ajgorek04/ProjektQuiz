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
    QFile file(":/csv/categories.csv");
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
    QFile file(":/questions/questions.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku questions.csv";
        return;
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

    // 🔀 Losowanie pytań
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(questions.begin(), questions.end(), g);

    currentQuestionIndex = 0;
    showQuestion();
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
    currentQuestionIndex++;
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
    const Question& q = questions[currentQuestionIndex];

    if (answer == q.getCorrectAnswer()) {
        ui->label_feedback->setText("✅ Dobra odpowiedź!");
    } else {
        ui->label_feedback->setText("❌ Zła odpowiedź! Poprawna: " + QString(q.getCorrectAnswer()));
    }

    ui->button_next->setEnabled(true);

    ui->button_answerA->setEnabled(false);
    ui->button_answerB->setEnabled(false);
    ui->button_answerC->setEnabled(false);
    ui->button_answerD->setEnabled(false);
}

void MainWindow::showQuestion()
{
    if (currentQuestionIndex >= questions.size()) {
        ui->label_question->setText("Koniec quizu!");
        ui->button_answerA->setEnabled(false);
        ui->button_answerB->setEnabled(false);
        ui->button_answerC->setEnabled(false);
        ui->button_answerD->setEnabled(false);
        ui->button_next->setEnabled(false);
        ui->label_category->clear(); // Czyść kategorię po zakończeniu
        return;
    }

    const Question& q = questions[currentQuestionIndex];

    ui->label_question->setText(q.getText());
    ui->label_category->setText("Kategoria: " + q.getCategory()); // 🆕 Wyświetl kategorię

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

