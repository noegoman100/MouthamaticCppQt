#include "filefetcher.h"
#include <QDir>

FileFetcher::FileFetcher() //constructor
{

}

QImage FileFetcher::fetchFile(QString fileName){ //I will receive a file name string, and I will return a QImage loaded with that file.

    QImage img(QDir::currentPath() + "/mouth_image_sets/" + fileName); //Create a QImage and load it with a fileName

    return img;

}
