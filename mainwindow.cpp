#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //Required Qt stuff
    ui->setupUi(this);

    //Uses global dbConnection object, and tries to connect to the database.
    //g_dbConnection returns a boolean, base on db.open()
    //Placed here in the constructor to happen automatically on window creation.
    if(g_dbConnection.connect()) {
        QMessageBox::information(this, "Connection", "Database Connected");
    } else {
        QMessageBox::information(this, "Not Connected", "Database Not Connected");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
    QApplication::exit();
}



void MainWindow::on_sendQueryButton_clicked()
{
    QVector<QString> resultVector{};
    QSqlQuery query;
    query.exec("SELECT * FROM `word-to-phoneme`.user");
    while(query.next()){

        QString result = query.value(1).toString();
        resultVector.push_back(result);
        qDebug() << result.toLocal8Bit().constData();
        qDebug() << resultVector.size();
        for (auto i: resultVector) qDebug() << i;
    }
}

void MainWindow::on_sentenceParserButton_clicked()
{
    QString rawSentence = "This is a raw sentence";
    SentenceParser sentenceParser;
    std::vector<Word> newWordVector = sentenceParser.parse(rawSentence);
    for(auto& value: newWordVector){
        qDebug() << value.wordName;
    }

}
