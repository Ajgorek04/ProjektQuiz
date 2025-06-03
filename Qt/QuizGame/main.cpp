#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Główna funkcja programu.
 * 
 * Tworzy aplikację Qt i pokazuje główne okno.
 * 
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return int Kod zakończenia aplikacji.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
