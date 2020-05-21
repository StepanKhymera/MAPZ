#ifndef TOKEN_H
#define TOKEN_H

#include <QMainWindow>

enum class functionsU {open,find_next,atr, none};

enum class functionsB {find_f,find_all, none};

enum class keywords { tag, file};



class Token
{
public:
    QString tag;
    QString value;
    Token();
    Token(QString lexem);
};
#endif // TOKEN_H
