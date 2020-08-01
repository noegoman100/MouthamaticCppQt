#include "dialogconverter.h"

/*
 *
 * This is the primary component of this application.
 * This object will be composed of SentenceParser, WordParser, and SymbolMapper objects.
 * The goal is to take the raw sentence, and work it all the way through to the image URLs.
 * Raw Sentence -> Parsed Sentence (individual words) -> Words with Symbols -> Words with Symbols and Image URLs
 * A vector of Words will be created and hold all the Word objects parsed from the raw sentence.
 *
 */

DialogConverter::DialogConverter() //Default Constructor
{
    qDebug() << "DialogConverter constructor called";
}

std::vector<Word> DialogConverter::convert(QString rawSentence){ //Get raw sentence from lineEdit in GUI
    qDebug() << "Dialog Converter recieved rawSentence: " << rawSentence; //Verifying that the input made it into this function.

    std::vector<Word> convertedDialog = sentenceParser->parse(rawSentence); //parse the input sentence, and place it into a new 'convertedDialog' vector of Words.
    for (auto& value: convertedDialog){ //Now run each word through the Word Parser, and get the constituent symbols from the database.
        qDebug() << "Inside Dialog Converter. After sentenceParser. Word Name: " << value.wordName; //Test to make sure the words were parsed and placed into the wordName variables inside the convertedDialog vector.
        value.symbols = wordParser->parseWord(value.wordName); //Takes the current Word object, sends the wordName for conversion to symbols, and stores the result inside itself (convertedDialog(vector)).
    }



    return convertedDialog;
}
