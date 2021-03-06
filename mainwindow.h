#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QLineEdit>
#include <QImage>

#include "sentenceparser.h"
#include "global.h"
#include "dialogconverter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_convertDialogButton_clicked();

private:
    Ui::MainWindow *ui;
    DialogConverter* dialogConverter = new DialogConverter();
};
#endif // MAINWINDOW_H
