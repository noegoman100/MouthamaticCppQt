#ifndef WORD_H
#define WORD_H

#include <qimage.h>
#include <qstring.h>
#include <vector>



struct Word
{
    QString wordName;
    std::vector<QString> symbols;
    std::vector<QString> imageUrl;
    std::vector<QImage> imageFile;
};

#endif // WORD_H
