#ifndef SENTENCEPARSER_H
#define SENTENCEPARSER_H

#include <QDebug>
#include "word.h"
#include "global.h"
#include "word.h"
#include <vector>



class SentenceParser
{
public:
    SentenceParser();
    std::vector<Word> parse(QString &rawSentence);
};

#endif // SENTENCEPARSER_H
