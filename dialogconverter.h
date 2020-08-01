#ifndef DIALOGCONVERTER_H
#define DIALOGCONVERTER_H

#include <vector>
#include <QString>
#include <QImage>
#include "sentenceparser.h"
#include "wordparser.h"


class DialogConverter
{
public:
    DialogConverter();
    //std::vector<QImage> convert(QString);
    std::vector<Word> convert(QString);
private:
    SentenceParser* sentenceParser = new SentenceParser();
    WordParser* wordParser = new WordParser();
};

#endif // DIALOGCONVERTER_H
