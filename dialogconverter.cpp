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

    //Initial Instance of allWords.
    std::vector<Word> allWords = sentenceParser->parse(rawSentence); //parse the input sentence, and place it into a new 'convertedDialog' vector of Words.
    for (auto& value: allWords){ //Now run each word through the Word Parser, and get the constituent symbols from the database.
        qDebug() << "Inside Dialog Converter. After sentenceParser. Word Name: " << value.wordName; //Test to make sure the words were parsed and placed into the wordName variables inside the convertedDialog vector.
        value.symbols = wordParser->parseWord(value.wordName); //Takes a word, and returns the symbols for that word. These symbols get stored in the parent Word vector.

    } //End For Loop
    for (auto& word: allWords){
        for (int i = 0; i < word.symbols.size(); i++){
            word.imageUrl.push_back(symbolMapper->mapSymboltoFileName(word.symbols[i], "3"));//get the FileName from the current symbol, add it to the imageURL vector of the same Word.
        }
    }


    return allWords;
}
