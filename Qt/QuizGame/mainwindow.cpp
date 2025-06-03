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

/**
 * @brief Konstruktor klasy MainWindow. Inicjalizuje interfejs i tło.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Quiz Game");
    ui->stackedWidget->setCurrentIndex(0);

    QPixmap background(":/background/images/background.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(background));
    this->setAutoFillBackground(true);
    this->setPalette(palette);
}

/**
 * @brief Destruktor klasy MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Obsługuje kliknięcie przycisku Start – przechodzi do strony wyboru trybu.
 */
void MainWindow::on_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief Obsługuje kliknięcie przycisku Wyjście – zamyka aplikację.
 */
void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}

/**
 * @brief Obsługuje kliknięcie przycisku Kategorie – ładuje kategorie i przechodzi do strony wyboru.
 */
void MainWindow::on_category_clicked()
{
    qDebug() << "Kliknięto category!";
    loadCategories();
    ui->stackedWidget->setCurrentIndex(4);
}

/**
 * @brief Ładuje dostępne kategorie z pliku CSV i dodaje je do listy kategorii w interfejsie.
 */
void MainWindow::loadCategories()
{
    QFile file(":/categories.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku categories.csv";
        return;
    }

    QTextStream in(&file);
    ui->listWidget_category->clear();
    ui->listWidget_category_2->clear();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            ui->listWidget_category->addItem(line);
            ui->listWidget_category_2->addItem(line);
        }
    }

    file.close();
}

/**
 * @brief Ładuje pytania z podanych kategorii i inicjuje pierwsze pytanie.
 * @param categories Lista wybranych kategorii.
 */
void MainWindow::loadQuestions(const QStringList &categories)
{
    if (quizManager.loadQuestions(":/questions.csv", categories)) {
        quizManager.shuffleQuestions();
        showQuestion();
    } else {
        qDebug() << "Błąd podczas ładowania pytań";
    }
}

/**
 * @brief Obsługuje przycisk powrotu do menu głównego.
 */
void MainWindow::on_back_button_clicked()
{
    correctAnswers = 0;
    totalRounds = 0;
    currentRound = 0;
    totalPlayers = 1;
    currentPlayer = 1;
    playerScores.clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_button2_clicked() { ui->stackedWidget->setCurrentIndex(0); }

void MainWindow::on_rules_clicked() { ui->stackedWidget->setCurrentIndex(5); }

void MainWindow::on_back_button3_clicked() { ui->stackedWidget->setCurrentIndex(0); }

void MainWindow::on_back_button4_clicked() { ui->stackedWidget->setCurrentIndex(0); }

/**
 * @brief Uruchamia tryb gry jednoosobowej.
 */
void MainWindow::on_tryb_gry1_clicked()
{
    totalPlayers = 1;
    currentPlayer = 1;
    correctAnswers = 0;

    loadCategories();
    ui->stackedWidget->setCurrentIndex(6);
}

/**
 * @brief Zwraca poprawnie odmienioną formę słowa "punkt" w zależności od liczby.
 * @param liczba Liczba punktów.
 * @return QString Odmieniona forma.
 */
QString odmienPunkty(int liczba) {
    if (liczba == 1)
        return "punkt";

    int ostatnieDwie = liczba % 100;
    int ostatnia = liczba % 10;

    if (ostatnieDwie >= 10 && ostatnieDwie <= 20)
        return "punktów";

    if (ostatnia >= 2 && ostatnia <= 4)
        return "punkty";

    return "punktów";
}

/**
 * @brief Obsługuje przejście do kolejnego pytania lub pokazuje wyniki po zakończeniu gry.
 */
void MainWindow::on_button_next_clicked()
{
    if (totalPlayers > 1) {
        currentPlayer++;
        if (currentPlayer > totalPlayers) {
            currentPlayer = 1;
            currentRound++;
        }
    } else {
        currentRound++;
    }

    if (currentRound > totalRounds) {
        ui->stackedWidget->setCurrentWidget(ui->page_result);

        if (totalPlayers == 1) {
            ui->label_result->setText(QString("Koniec gry!\nTwój wynik: %1 / %2").arg(correctAnswers).arg(totalRounds));
        } else {
            QString rankingText = "🏆 Wyniki:\n\n";
            QVector<QPair<int, int>> results;

            for (int i = 0; i < playerScores.size(); ++i) {
                results.append(qMakePair(i, playerScores[i]));
            }

            std::sort(results.begin(), results.end(), [](const QPair<int, int>& a, const QPair<int, int>& b) {
                return a.second > b.second;
            });

            for (int i = 0; i < results.size(); ++i) {
                QString medal;
                if (i == 0) medal = "🥇";
                else if (i == 1) medal = "🥈";
                else if (i == 2) medal = "🥉";

                int playerNumber = results[i].first + 1;
                int points = results[i].second;
                rankingText += QString("%1 Gracz %2: %3 %4\n")
                                   .arg(medal)
                                   .arg(playerNumber)
                                   .arg(points)
                                   .arg(odmienPunkty(points));
            }

            ui->label_result->setText(rankingText);
        }

        return;
    }

    quizManager.nextQuestion();
    showQuestion();
}

// Obsługa odpowiedzi użytkownika:
void MainWindow::on_button_answerA_clicked() { checkAnswer('A'); }
void MainWindow::on_button_answerB_clicked() { checkAnswer('B'); }
void MainWindow::on_button_answerC_clicked() { checkAnswer('C'); }
void MainWindow::on_button_answerD_clicked() { checkAnswer('D'); }

/**
 * @brief Sprawdza poprawność odpowiedzi i aktualizuje wynik.
 * @param answer Litera odpowiedzi ('A' - 'D').
 */
void MainWindow::checkAnswer(QChar answer)
{
    if (quizManager.checkAnswer(answer)) {
        ui->label_feedback->setText("✅ Dobra odpowiedź!");
        correctAnswers++;
        if (totalPlayers > 1) {
            if (playerScores.size() < totalPlayers)
                playerScores.resize(totalPlayers);
            playerScores[currentPlayer - 1]++;
        }
    } else {
        ui->label_feedback->setText("❌ Zła odpowiedź! Poprawna: " + QString(quizManager.currentQuestion().getCorrectAnswer()));
    }

    ui->button_next->setEnabled(true);
    ui->button_answerA->setEnabled(false);
    ui->button_answerB->setEnabled(false);
    ui->button_answerC->setEnabled(false);
    ui->button_answerD->setEnabled(false);
}

/**
 * @brief Wyświetla aktualne pytanie i odpowiedzi.
 */
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

void MainWindow::on_button_back_to_menu_clicked() { ui->stackedWidget->setCurrentIndex(0); }

void MainWindow::on_button_start_rounds_clicked()
{
    bool ok;
    int rounds = ui->lineEdit_rounds->text().toInt(&ok);

    if (ok && rounds > 0) {
        totalRounds = rounds;
        currentRound = 1;
        ui->stackedWidget->setCurrentIndex(2);
        loadQuestions();
    } else {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawną liczbę rund!");
    }
}

void MainWindow::on_exit_2_clicked() { QApplication::quit(); }

void MainWindow::on_button_return_to_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    totalRounds = 0;
    currentRound = 0;
    correctAnswers = 0;
}

void MainWindow::on_button_return_to_menu_2_clicked() { ui->stackedWidget->setCurrentIndex(0); }

void MainWindow::on_tryb_gry_multiplayer_clicked()
{
    totalPlayers = 0;
    currentPlayer = 1;
    correctAnswers = 0;
    loadCategories();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_button_start_multiplayer_clicked()
{
    playerScores.clear();
    correctAnswers = 0;
    currentRound = 1;
    currentPlayer = 1;

    bool okRounds, okPlayers;
    int rounds = ui->lineEdit_multi_rounds->text().toInt(&okRounds);
    int players = ui->lineEdit_players_count->text().toInt(&okPlayers);

    if (okRounds && rounds > 0 && okPlayers && players > 0) {
        totalRounds = rounds;
        totalPlayers = players;
        playerScores.resize(totalPlayers, 0);

        loadQuestions();
        ui->stackedWidget->setCurrentIndex(2);
        showQuestion();
    } else {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawną liczbę rund i graczy!");
    }
}

void MainWindow::on_radio_mixed_toggled(bool checked)
{
    if (checked) {
        ui->listWidget_category_2->setEnabled(false);
        ui->listWidget_category_2->clearSelection();
    }
}

void MainWindow::on_radio_select_toggled(bool checked)
{
    ui->listWidget_category_2->setEnabled(checked);
}

void MainWindow::on_back_button3_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_button_confirm_category_clicked()
{
    QStringList selectedCategories;

    if (ui->radio_select->isChecked()) {
        auto selectedItems = ui->listWidget_category_2->selectedItems();
        if (selectedItems.isEmpty()) {
            QMessageBox::warning(this, "Uwaga", "Wybierz przynajmniej jedną kategorię lub przełącz na 'Mieszane kategorie'");
            return;
        }

        for (auto item : selectedItems) {
            selectedCategories.append(item->text());
        }
    }

    loadQuestions(selectedCategories);
    ui->stackedWidget->setCurrentIndex(3);
}
