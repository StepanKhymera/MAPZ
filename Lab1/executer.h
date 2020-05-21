#ifndef EXECUTER_H
#define EXECUTER_H

#include "parser.h"

class Executer
{
public:
    QVector<Node*> tree;
    QMap<QString , QString> table;
    void ExecuteAll();
    Executer();
};

#endif // EXECUTER_H
