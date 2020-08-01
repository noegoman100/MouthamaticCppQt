#ifndef WORDPARSER_H
#define WORDPARSER_H

#include <vector>
#include <QString>
#include <QSqlQuery>
#include "word.h"
#include "global.h"


class WordParser
{
public:
    WordParser();
    std::vector<QString> parseWord(QString);
};

#endif // WORDPARSER_H
