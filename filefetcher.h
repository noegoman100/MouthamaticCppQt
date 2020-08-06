#ifndef FILEFETCHER_H
#define FILEFETCHER_H

#include <QImage>
#include <QString>

class FileFetcher
{
public:
    FileFetcher(); //Constructor
    QImage fetchFile(QString);
};

#endif // FILEFETCHER_H
