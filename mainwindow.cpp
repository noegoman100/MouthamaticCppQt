#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QPixmap>
#include <QImage>
#include <QLabel>
#include <QVBoxLayout>

QLabel* labelPtr{nullptr}; //Create a pointer to a label. For on_convertDialogButton_clicked()
QVBoxLayout* imageVerticalLayout{nullptr};//Create a pointer to a VBoxLayout. For on_convertDialogButton_clicked()

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


void MainWindow::on_convertDialogButton_clicked()
{
    QString rawSentence = "This is a raw sentence"; //Basic initialization

    int numObjectsToDelete{0}; //I will use this to loop through and delete all the old objects to prevent memory leak.
    qDebug() << "convertDialogButton clicked, with input: " << ui->rawSentenceLineEdit->text();  //Verify the function received the input text.
    if(imageVerticalLayout != nullptr){ //Just looking to see if the count() works. Crashes if it is nullPtr.
        qDebug() << "previous image count: " << imageVerticalLayout->count();
        numObjectsToDelete = imageVerticalLayout->count();
        for (int i = 0; i < numObjectsToDelete; i++){
            //delete imageVerticalLayout->itemAt(i); //Free up memory used in previous conversion (if any) //Crashes program. Look into QPointer class.
            //qDebug() << "Deleted object at index: " << i;

            qDebug() << "Object names: " << imageVerticalLayout->itemAt(i)->widget()->objectName();
        }
    }



    rawSentence = ui->rawSentenceLineEdit->text();

    //allWords is the primary data object that will hold all the parsed info about the raw input sentence.
    std::vector<Word> allWords = dialogConverter->convert(rawSentence);

    //Load the image scroll area with the returned images.
    //QLabel* labelPtr{nullptr}; //Create a pointer to a label.
    delete labelPtr; //Free memory, if used.
    delete imageVerticalLayout; //Free memory, if used.
    imageVerticalLayout = new QVBoxLayout();
    ui->imageScrollArea->setWidget(new QWidget);
    ui->imageScrollArea->widget()->setLayout(imageVerticalLayout);
    for (auto& word: allWords){
        for (auto& image: word.imageFile){
            labelPtr = new QLabel(); //Possible memory leak. Please investigate. Qt may take care of this.
            //labelPtr->setFixedSize(300,200);
            labelPtr->setPixmap(QPixmap::fromImage(image));
            imageVerticalLayout->addWidget(labelPtr); //This layout holds all of the labelPtr pointers.
            //imageVerticalLayout->   //Maybe cycle through and delete all the Qlabel objects.
        }

    }

//Debugging - Temporary
//    for (auto& value: allWords){ //Verifying the results of the dialogConverter
//        qDebug() << "Word Name: " << value.wordName;
//        for (auto& subValue1: value.symbols){
//            qDebug() << "Symbols: " << subValue1;
//        }
//        for (auto& subValue2: value.imageUrl){
//            qDebug() << "imageUrls: " << subValue2;
//        }
//        for (auto& subValue3: value.imageFile){
//            qDebug() << "Image Exists";
//        }
//    }






}
