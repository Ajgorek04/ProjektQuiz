#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QPalette>
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QTextStream>

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


void MainWindow::on_start_clicked()
{
    QMessageBox::information(this, "Start", "Rozpoczynamy grę!");
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_category_clicked()
{
    loadCategories();
    ui->stackedWidget->setCurrentIndex(1);
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
    ui->stackedWidget->setCurrentIndex(2);
}



