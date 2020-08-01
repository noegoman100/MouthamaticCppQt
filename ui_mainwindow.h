/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *exitButton;
    QPushButton *sendQueryButton;
    QPushButton *convertDialogButton;
    QLineEdit *rawSentenceLineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(710, 560, 81, 16));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(710, 530, 75, 23));
        sendQueryButton = new QPushButton(centralwidget);
        sendQueryButton->setObjectName(QString::fromUtf8("sendQueryButton"));
        sendQueryButton->setGeometry(QRect(710, 490, 75, 23));
        convertDialogButton = new QPushButton(centralwidget);
        convertDialogButton->setObjectName(QString::fromUtf8("convertDialogButton"));
        convertDialogButton->setGeometry(QRect(280, 50, 141, 23));
        rawSentenceLineEdit = new QLineEdit(centralwidget);
        rawSentenceLineEdit->setObjectName(QString::fromUtf8("rawSentenceLineEdit"));
        rawSentenceLineEdit->setGeometry(QRect(20, 10, 401, 20));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hello World!", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit Button", nullptr));
        sendQueryButton->setText(QCoreApplication::translate("MainWindow", "Send Query", nullptr));
        convertDialogButton->setText(QCoreApplication::translate("MainWindow", "Convert Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
