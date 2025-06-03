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
 * @brief Klasa MainWindow — główne okno aplikacji Quiz.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy MainWindow.
     * @param parent Wskaźnik na obiekt nadrzędny (domyślnie nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor klasy MainWindow.
     */
    ~MainWindow();

private slots:
    // === Sloty obsługujące przyciski i interakcje GUI ===
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
    Ui::MainWindow *ui; ///< Wskaźnik na interfejs użytkownika (UI) wygenerowany przez Qt Designer.

    QuizManager quizManager; ///< Obiekt zarządzający pytaniami, kategoriami i stanem quizu.

    int currentQuestionIndex = 0; ///< Indeks aktualnego pytania w bieżącej rozgrywce.
    int totalRounds = 0;          ///< Liczba zaplanowanych rund w trybie gry.
    int currentRound = 0;         ///< Numer aktualnej rundy.
    int correctAnswers = 0;       ///< Liczba poprawnych odpowiedzi danego gracza.
    int totalPlayers = 1;         ///< Liczba graczy (1 = tryb solo, 2+ = multiplayer).
    int currentPlayer = 1;        ///< Numer aktualnego gracza w trybie multiplayer.
    QVector<int> playerScores;    ///< Tablica punktów zdobytych przez poszczególnych graczy.

    /**
     * @brief Wczytuje dostępne kategorie quizu (np. sport, historia).
     */
    void loadCategories();

    /**
     * @brief Wczytuje pytania quizu na podstawie wybranych kategorii.
     * @param categories Lista wybranych kategorii (domyślnie wszystkie).
     */
    void loadQuestions(const QStringList &categories = QStringList());

    /**
     * @brief Wyświetla aktualne pytanie i możliwe odpowiedzi w UI.
     */
    void showQuestion();

    /**
     * @brief Sprawdza, czy wybrana odpowiedź jest poprawna i aktualizuje wynik.
     * @param answer Litera odpowiedzi ('A', 'B', 'C', 'D').
     */
    void checkAnswer(QChar answer);
};

#endif // MAINWINDOW_H
