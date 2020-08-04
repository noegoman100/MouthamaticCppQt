#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QPixmap>
#include <QImage>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //Required Qt stuff
    ui->setupUi(this);
    //dialogConverter = new DialogConverter();

    //Uses global dbConnection object, and tries to connect to the database.
    //g_dbConnection returns a boolean, base on db.open()
    //Placed here in the constructor to happen automatically on window creation.
    if(g_dbConnection.connect()) { //Uncomment me to connect to database.
    //if(1==0){ //TEMP
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
    //query.exec("SELECT * FROM `word-to-phoneme`.user");
    query.exec("SELECT * FROM user");
    while(query.next()){

        QString result = query.value(1).toString();
        resultVector.push_back(result);
        qDebug() << result.toLocal8Bit().constData();
        qDebug() << resultVector.size();
        for (auto i: resultVector) qDebug() << i;
    }
}

void MainWindow::on_convertDialogButton_clicked()
{
    QString rawSentence = "This is a raw sentence";

    qDebug() << "convertDialogButton clicked, with input: " << ui->rawSentenceLineEdit->text();
    rawSentence = ui->rawSentenceLineEdit->text();

    std::vector<Word> allWords = dialogConverter->convert(rawSentence);

    for (auto& value: allWords){ //Verifying the results of the dialogConverter
        qDebug() << "Word Name: " << value.wordName;
        for (auto& subValue1: value.symbols){
            qDebug() << "Symbols: " << subValue1;
        }
        for (auto& subValue2: value.imageUrl){
            qDebug() << "imageUrls: " << subValue2;
        }
    }

    //Testing out QPixmap and QLabel to show an image.
    //QPixmap img(QDir::currentPath() + "/mouth_image_sets/mouth_image_setsMike-LipSet-Layers-AlphaLARGE_08.png");
    QImage img;
    img.load(QDir::currentPath() + "/mouth_image_sets/Mike-LipSet-Layers-AlphaLARGE_08.png");
    //ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setPixmap(QPixmap::fromImage(img));

}
