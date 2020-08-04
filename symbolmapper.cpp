#include <QSqlQuery>
#include <QDebug>
#include "symbolmapper.h"

SymbolMapper::SymbolMapper() //default constructor
{

}

QString SymbolMapper::mapSymboltoFileName(QString symbol, QString selectedImageSet){


//From Java version.
//    "SELECT image_url FROM `word-to-phoneme`.image_map WHERE symbol_id_pk2 = "
//    + sentenceData.getParsedSentenceWordsList().get(i).getPhonemes().get(j)
//    + " AND mouth_pair_id_pk1 = " + mouth_pair_id
//    + ";");

    QSqlQuery query;
    QString queryString1 = "SELECT image_url FROM image_map WHERE symbol_id_pk2 = ";
    QString queryString2 = symbol;
    QString queryString3 = " AND mouth_pair_id_pk1 = ";
    QString queryString4 = selectedImageSet;
    QString queryString5 = ";";
    //qDebug() << queryString1 + queryString2 + queryString3 + queryString4 + queryString5;
    query.exec(queryString1 + queryString2 + queryString3 + queryString4 + queryString5);
    QString fileName;
    while(query.next()){ //Should only iterate once - only one item should be returned from the query.
        fileName = query.value(0).toString();
    }
    return fileName;

}
