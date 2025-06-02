#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../src/question.h"
#include "../../src/quizmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Główne okno aplikacji Quiz.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor MainWindow.
     * @param parent Rodzic okna.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor MainWindow.
     */
    ~MainWindow();

private slots:
    // Sloty obsługujące przyciski i zdarzenia w GUI
    void on_start_clicked();
    void on_exit_clicked();
    void on_category_clicked();
    void on_back_button_clicked();
    void on_rules_clicked();
    void on_back_button2_clicked();
    void on_back_button3_clicked();
    void on_back_button4_clicked();
    void on_tryb_gry1_clicked();
    void on_button_next_clicked();
    void on_button_answerA_clicked();
    void on_button_answerB_clicked();
    void on_button_answerC_clicked();
    void on_button_answerD_clicked();
    void on_button_back_to_menu_clicked();
    void on_button_start_rounds_clicked();
    void on_exit_2_clicked();
    void on_button_return_to_menu_clicked();
    void on_button_return_to_menu_2_clicked();
    void on_tryb_gry_multiplayer_clicked();
    void on_button_start_multiplayer_clicked();
    void on_radio_mixed_toggled(bool checked);
    void on_radio_select_toggled(bool checked);
    void on_back_button3_2_clicked();
    void on_button_confirm_category_clicked();


private:
    Ui::MainWindow *ui; ///< Wskaźnik na UI wygenerowane przez Qt Designer.

    QuizManager quizManager; ///< Obiekt zarządzający pytaniami w quizie.

    int currentQuestionIndex = 0; ///< Indeks aktualnego pytania.
    int totalRounds = 0; ///< Całkowita liczba rund.
    int currentRound = 0; ///< Aktualna runda.
    int correctAnswers = 0; ///< Liczba poprawnych odpowiedzi.
    int totalPlayers = 1; ///< Liczba graczy (1 = solo).
    int currentPlayer = 1; ///< Aktualny gracz w rozgrywce wieloosobowej.
    QVector<int> playerScores; ///< Wyniki poszczególnych graczy.

    /**
     * @brief Wczytuje dostępne kategorie quizu.
     */
    void loadCategories();

    /**
     * @brief Wczytuje pytania quizu.
     */
    void loadQuestions(const QStringList &categories = QStringList());

    /**
     * @brief Wyświetla aktualne pytanie na ekranie.
     */
    void showQuestion();

    /**
     * @brief Sprawdza odpowiedź użytkownika.
     * @param answer Wybrana odpowiedź ('A', 'B', 'C', 'D').
     */
    void checkAnswer(QChar answer);
};

#endif // MAINWINDOW_H
