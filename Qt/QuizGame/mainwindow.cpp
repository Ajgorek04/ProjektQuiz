#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QPalette>
#include <QPixmap>
#include <QDebug> // Do debugowania

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Quiz Game");

    QPixmap background(":/background/images/background.jpg");
    if (background.isNull()) {
        qDebug() << "Nie udało się załadować obrazka!";
    } else {
        qDebug() << "Obrazek załadowany!";
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(background));
        this->setAutoFillBackground(true);
        this->setPalette(palette);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    QMessageBox::information(this, "Start", "Rozpoczynamy grę!");
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}

