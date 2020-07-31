#include "sentenceparser.h"
#include <iostream>
#include <string>
#include <sstream>


SentenceParser::SentenceParser() //Constructor
{

}

std::vector<Word> SentenceParser::parse(QString& rawSentence){
    qDebug() << "rawSentence received: " << rawSentence;

    QStringList list;
    list = rawSentence.split(QRegExp("\\W+"));


    std::vector<Word> wordVector;
    for (int i = 0; i < list.size(); i++){
        Word parsedWord;
        parsedWord.wordName = list.at(i).toLocal8Bit().constData();
        wordVector.push_back(parsedWord);
    }


    return wordVector;
}
