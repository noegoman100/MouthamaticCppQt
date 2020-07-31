#ifndef WORDPARSER_H
#define WORDPARSER_H

#include <vector>
#include <QString>
#include "word.h"


class WordParser
{
public:
    WordParser();
    std::vector<QString> parseWord(Word);
};

#endif // WORDPARSER_H
