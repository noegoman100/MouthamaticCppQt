#include "wordparser.h"
#include <QDebug>

WordParser::WordParser() //Constructor
{

}

std::vector<QString> WordParser::parseWord(QString word){
    /**
     * FROM JAVA version:
     * query = "SELECT word_name, word_id_pk1, part_segment_pk2, symbol_id_fk FROM `word-to-phoneme`.word_parts
     * JOIN `word-to-phoneme`.word ON word_id = word_id_pk1 WHERE word_name = \""
     * + sentenceData.getParsedSentenceWordsList().get(i).getWord_name() + "\";";
     *
     */

    QSqlQuery query;
    QString queryString1 = "SELECT word_name, word_id_pk1, part_segment_pk2, symbol_id_fk FROM `word-to-phoneme`.word_parts ";
    QString queryString2 = "JOIN `word-to-phoneme`.word ON word_id = word_id_pk1 WHERE word_name = \"";
    QString queryString3 = word;
    QString queryString4 = "\";";
    qDebug() << queryString1 << queryString2 << queryString3 << queryString4;
    //query.exec(queryString1 + queryString2 + queryString3 + queryString4);

    std::vector<QString> tempVector;
    QString tempQString = "No symbols yet";
    tempVector.push_back(tempQString);
    return tempVector; //Todo Replace me with actual results from the database.
}
