#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../src/question.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
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

private:
    Ui::MainWindow *ui;
    void loadCategories();
    void loadQuestions();
    void showQuestion();
    void checkAnswer(QChar answer);

    QVector<Question> questions;
    int currentQuestionIndex = 0;
};
#endif // MAINWINDOW_H
