#include "filefetcher.h"
#include <QDir>

FileFetcher::FileFetcher() //constructor
{

}

QImage FileFetcher::fetchFile(QString fileName){ //I will receive a file name string, and I will return a QImage loaded with that file.

    //    //Testing out the imageScrollArea
    //    QImage img(QDir::currentPath() + "/mouth_image_sets/Mike-LipSet-Layers-AlphaLARGE_08.png"); //Create a QImage and load it with a fileName
    //    QLabel* labelPtr; //Create a pointer to a label.
    //    QVBoxLayout* imageVerticalLayout = new QVBoxLayout();
    //    ui->imageScrollArea->setWidget(new QWidget);
    //    ui->imageScrollArea->widget()->setLayout(imageVerticalLayout);
    //    for (int i = 0; i < 15; i++){
    //        labelPtr = new QLabel(); //Possible memory leak. Please investigate. Qt may take care of this.
    //        labelPtr->setFixedSize(300,200);
    //        labelPtr->setPixmap(QPixmap::fromImage(img));
    //        imageVerticalLayout->addWidget(labelPtr);
    //    }

    QImage img(QDir::currentPath() + "/mouth_image_sets/" + fileName); //Create a QImage and load it with a fileName

    return img;

}
