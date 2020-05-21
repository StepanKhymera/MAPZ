#ifndef LEXER_H
#define LEXER_H

#include <QMainWindow>

#include "token.h"

class Lexer
{
public:
    QVector<QVector<Token*>> *tokens;

    Lexer();
    QString BREAK_DOWN(QString data);
};

#endif // LEXER_H
