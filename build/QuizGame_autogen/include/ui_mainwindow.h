/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QSplitter *splitter;
    QPushButton *start;
    QPushButton *rules;
    QPushButton *category;
    QPushButton *exit;
    QLabel *label;
    QWidget *page2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_button3;
    QPushButton *nextQuestion;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QWidget *page3;
    QListWidget *listWidget_category;
    QPushButton *back_button;
    QLabel *label_4;
    QWidget *page4;
    QLabel *label_7;
    QTextBrowser *textBrowser;
    QPushButton *back_button2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(812, 631);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, 0, 811, 631));
        stackedWidget->setFrameShape(QFrame::Shape::NoFrame);
        page = new QWidget();
        page->setObjectName("page");
        splitter = new QSplitter(page);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(260, 350, 271, 211));
        splitter->setOrientation(Qt::Orientation::Vertical);
        start = new QPushButton(splitter);
        start->setObjectName("start");
        start->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}"));
        splitter->addWidget(start);
        rules = new QPushButton(splitter);
        rules->setObjectName("rules");
        rules->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color: #0099cc;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:  #007399 ;\n"
"}"));
        splitter->addWidget(rules);
        category = new QPushButton(splitter);
        category->setObjectName("category");
        category->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color: #ffcc66;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:   #ffaa00 ;\n"
"}"));
        splitter->addWidget(category);
        exit = new QPushButton(splitter);
        exit->setObjectName("exit");
        exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color:  #737373 ;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #595959;\n"
"}"));
        splitter->addWidget(exit);
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 10, 511, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Script")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"font-size: 36px;\n"
"font-weight: bold;"));
        label->setFrameShape(QFrame::Shape::NoFrame);
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page);
        page2 = new QWidget();
        page2->setObjectName("page2");
        label_2 = new QLabel(page2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 741, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"font-size: 36px;\n"
"font-weight: bold;"));
        label_2->setFrameShape(QFrame::Shape::NoFrame);
        label_2->setTextFormat(Qt::TextFormat::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayoutWidget = new QWidget(page2);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 550, 703, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        back_button3 = new QPushButton(horizontalLayoutWidget);
        back_button3->setObjectName("back_button3");
        back_button3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color:  #737373 ;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"	margin-right: 100px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #595959;\n"
"}"));

        horizontalLayout->addWidget(back_button3);

        nextQuestion = new QPushButton(horizontalLayoutWidget);
        nextQuestion->setObjectName("nextQuestion");
        nextQuestion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    background-color:  #737373 ;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"	margin-left: 100px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #595959;\n"
"}"));

        horizontalLayout->addWidget(nextQuestion);

        formLayoutWidget = new QWidget(page2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(190, 360, 448, 166));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        radioButton1 = new QRadioButton(formLayoutWidget);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    padding: 15px 50px;\n"
"    margin: 5px;\n"
"    background-color: #388E3C;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #388E3C;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton:hover {\n"
"    background-color: #4CAF50;\n"
"    border-color: #4CAF50;\n"
"}\n"
"\n"
"QRadioButton#radioButton1:checked {\n"
"    background-color: #2E7D32;\n"
"    border-color: #2E7D32;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, radioButton1);

        radioButton2 = new QRadioButton(formLayoutWidget);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    padding: 15px 50px;\n"
"    margin: 5px;\n"
"    background-color: #D32F2F;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #D32F2F;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton:hover {\n"
"    background-color: #F44336;\n"
"    border-color: #F44336;\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #C62828;\n"
"    border-color: #C62828;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, radioButton2);

        radioButton3 = new QRadioButton(formLayoutWidget);
        radioButton3->setObjectName("radioButton3");
        radioButton3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    padding: 15px 50px;\n"
"    margin: 5px;\n"
"    background-color: #1976D2;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #1976D2;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton:hover {\n"
"    background-color: #2196F3;\n"
"    border-color: #2196F3;\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #1565C0;\n"
"    border-color: #1565C0;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, radioButton3);

        radioButton4 = new QRadioButton(formLayoutWidget);
        radioButton4->setObjectName("radioButton4");
        radioButton4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font-size: 18px;\n"
"    padding: 15px 50px;\n"
"    margin: 5px;\n"
"    background-color: #FF9800;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #FF9800;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton:hover {\n"
"    background-color: #FFB74D;\n"
"    border-color: #FFB74D;\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FB8C00;\n"
"    border-color: #FB8C00;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, radioButton4);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        listWidget_category = new QListWidget(page3);
        listWidget_category->setObjectName("listWidget_category");
        listWidget_category->setGeometry(QRect(270, 70, 261, 441));
        listWidget_category->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: white;\n"
"text-align: center;\n"
"font-size: 24px;\n"
"border: 1px solid black;\n"
"border-radius: 10px;"));
        listWidget_category->setFrameShape(QFrame::Shape::NoFrame);
        back_button = new QPushButton(page3);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(280, 530, 241, 41));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    color: white;\n"
"    font-size: 22px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"	background: transparent;\n"
"	border: 1px solid #fff;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgba(0, 0, 0, 0.1);\n"
"}"));
        label_4 = new QLabel(page3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 20, 781, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"font-size: 36px;\n"
"font-weight: bold;"));
        label_4->setFrameShape(QFrame::Shape::NoFrame);
        label_4->setTextFormat(Qt::TextFormat::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName("page4");
        page4->setStyleSheet(QString::fromUtf8("border: none;"));
        label_7 = new QLabel(page4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 781, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"font-size: 36px;\n"
"font-weight: bold;"));
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setTextFormat(Qt::TextFormat::AutoText);
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textBrowser = new QTextBrowser(page4);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 50, 741, 481));
        QFont font1;
        font1.setPointSize(16);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: #fff;\n"
"background-color: rgba(0, 0, 0, 0.1);\n"
"border-radius: 10px;"));
        back_button2 = new QPushButton(page4);
        back_button2->setObjectName("back_button2");
        back_button2->setGeometry(QRect(290, 550, 241, 41));
        back_button2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    vertical-align: middle;\n"
"    padding: 10px;\n"
"    color: white;\n"
"    font-size: 22px;\n"
"    border-radius: 10px;\n"
"	font-weight: bold;\n"
"	background: transparent;\n"
"	border: 1px solid #fff;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgba(0, 0, 0, 0.1);\n"
"}"));
        stackedWidget->addWidget(page4);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        rules->setText(QCoreApplication::translate("MainWindow", "ZASADY", nullptr));
        category->setText(QCoreApplication::translate("MainWindow", "KATEGORIE", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "WYJ\305\232CIE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "QUIZ GAME", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "QUIZ GAME", nullptr));
        back_button3->setText(QCoreApplication::translate("MainWindow", "POWR\303\223T DO MENU", nullptr));
        nextQuestion->setText(QCoreApplication::translate("MainWindow", "NAST\304\230PNE PYTANIE", nullptr));
        radioButton1->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton3->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton4->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        back_button->setText(QCoreApplication::translate("MainWindow", "POWR\303\223T", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "KATEGORIE", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ZASADY GRY", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">Wyb\303\263r kategorii</span><span style=\" font-size:11pt;\"><br />Gracz wybiera jedn\304\205 z dost\304\231pnych kategorii, takich jak: Auta, Jedzenie, Pa\305\204stwa, Muzyka itd.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; "
                        "font-weight:700;\">Rozpocz\304\231cie gry</span><span style=\" font-size:11pt;\"><br />Po wybraniu kategorii rozpoczyna si\304\231 quiz zawieraj\304\205cy pytania zwi\304\205zane z t\304\205 kategori\304\205.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">Odpowiadanie na pytania</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ka\305\274de pytanie ma kilka mo\305\274liwych odpowiedzi (jedna prawid\305\202owa).</li>\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Gracz wybiera odpowied\305\272 klikaj\304\205c w przycisk.</li>\n"
"<li style=\""
                        " font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Po ka\305\274dej odpowiedzi gracz otrzymuje informacj\304\231, czy by\305\202a poprawna.</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">Punktacja</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Za ka\305\274d\304\205 poprawn\304\205 odpowied\305\272 gracz otrzymuje 1 punkt.</li>\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Za z\305\202\304\205 odpowied\305\272 punkt\303\263w si\304\231 nie traci, ale n"
                        "ie s\304\205 przyznawane.</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">Zako\305\204czenie gry</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Gra ko\305\204czy si\304\231 po odpowiedzeniu na wszystkie pytania w wybranej kategorii.</li>\n"
"<li style=\" font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Na koniec gracz widzi sw\303\263j wynik i mo\305\274e wr\303\263ci\304\207 do menu g\305\202\303\263wnego.</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" fo"
                        "nt-size:11pt; font-weight:700;\">Wyj\305\233cie z gry</span><span style=\" font-size:11pt;\"><br />W ka\305\274dej chwili mo\305\274na wr\303\263ci\304\207 do menu lub zako\305\204czy\304\207 gr\304\231 przyciskiem &quot;WYJ\305\232CIE&quot;.</span></p></body></html>", nullptr));
        back_button2->setText(QCoreApplication::translate("MainWindow", "POWR\303\223T", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
