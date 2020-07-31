#include "wordparser.h"

WordParser::WordParser() //Constructor
{

}

std::vector<QString> parseWord(Word word){
    /**
     * FROM JAVA version:
     * query = "SELECT word_name, word_id_pk1, part_segment_pk2, symbol_id_fk FROM `word-to-phoneme`.word_parts JOIN `word-to-phoneme`.word ON word_id = word_id_pk1 WHERE word_name = \""
     *                  + sentenceData.getParsedSentenceWordsList().get(i).getWord_name() + "\";";
     *
     */

    return std::vector<QString>(); //TEMP
}
