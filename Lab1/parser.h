#ifndef PARSER_H
#define PARSER_H

#include <QMainWindow>
#include <token.h>
#include <node.h>


class Parser
{
public:
    QStandardItem* display_node_run;
    QVector<QVector<Token*>> tokens;
    QVector<Node*> tree;
    Token current;
    QStandardItemModel* model_raw;
    QStandardItemModel* model_optimized;

    Parser();
    void parse();
    QVector<Token*> line;
    DeclarationNode* parseDeclaration();
    InitialiseNode* parseInitialise();
    Expression* parseExpresion(int start);
    FunctionUExp* parseFunctionU(int start);
    FunctionBExp* parseFunctionB(int start);
    functionsU convert_typeU(int start);
    functionsB convert_typeB(int start);
    AssingNode* parseAssingNode();
    CurlBracStm* parseCurlBracStm(int* i);
    IfStm* parseIfStm(int* i);
    WhileStm* parseWhileStm(int* i);
    void optimize();
};

#endif // PARSER_H
