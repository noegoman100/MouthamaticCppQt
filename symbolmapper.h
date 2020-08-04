#ifndef SYMBOLMAPPER_H
#define SYMBOLMAPPER_H

#include <QString>


class SymbolMapper
{
public:
    SymbolMapper();
    QString mapSymboltoFileName(QString, QString); //Takes symbol, and selectedImageSet and Returns FileName
};

#endif // SYMBOLMAPPER_H
