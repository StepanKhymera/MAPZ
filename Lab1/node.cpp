#include "node.h"

#include <QMap>
#include <QDebug>

//#include <Q_
//#include <QMainWindow>
QString DeclarationNode::execute(QMap<QString, QString> table){
    if(!table.contains(id))
    {
        table.insert(id,"");
        return id;
    }
}

QString AssingNode::execute(QMap<QString, QString> table){

    if(table.contains(this->var->id)){

        QString expression = this->expr->execute(table);
        table[this->var->id] = expression;
    }

}

QString VariableExp::execute(QMap<QString, QString> table){
    if(table.contains(this->id)){
        return table[this->id];
    }
};

QString StringExp::execute(QMap<QString, QString> table){
    return this->value;
}

QString HTML_TagExp::execute(QMap<QString, QString> table){
    return  this->value;
}

QString InitialiseNode::execute(QMap<QString, QString> table){
    this->dec->execute(table);
    if(table.contains(this->dec->id )){

        QString expression = this->expr->execute(table);
        table[this->dec->id] = expression;
    }
}

QString FunctionBExp::execute(QMap<QString, QString> table){
    QString result1 = this->param1->execute(table);
    QString result2 = this->param2->execute(table);

    if(this->type == functionsB::find_f){
        return find_f(result1, result2);
    }

    if(this->type == functionsB::find_all){
        return find_all(result1, result2);
    }

}

QString FunctionBExp::find_f(QString result1, QString result2){

}

QString FunctionBExp::find_all(QString result1, QString result2){

}

QString FunctionUExp::execute(QMap<QString, QString> table){
    QString param_result = this->param->execute(table);

    if(this->type == functionsU::atr){
        return this->atr(param_result);
    }
    if(this->type == functionsU::open){

    }
    if(this->type == functionsU::find_next){

    }
}

QString FunctionUExp::open(QString result1){

}

QString FunctionUExp::atr(QString result1){

}

QString FunctionUExp::find_next(QString result1){

}

bool IfStm::checkCondition(Expression *condition, QMap<QString, QString> table){
    QString result = condition->execute(table);

    if(result == ""){
        return false;
    } else {
        return true;
    }
}

QString IfStm::execute(QMap<QString, QString> table){
    bool condit = this->checkCondition(condition, table);

    if(condit){
        this->body->execute(table);
    }else {
        return "0";
    }

}

QString WhileStm::execute(QMap<QString, QString> table){
    bool condit = IfStm::checkCondition(condition, table);

    while (condit) {
        this->body->execute(table);
        condit = IfStm::checkCondition(condition, table);
    }
}

QString CurlBracStm::execute(QMap<QString, QString> table){
    while(!this->body.isEmpty()){
        this->body.takeFirst()->execute(table);
    }
    return "";
}

QStandardItem* DeclarationNode::optimize(){
    QStandardItem* display_node = new QStandardItem("Declaration");

    display_node->appendRow(new QStandardItem(this->id));
    display_node->appendRow(new QStandardItem(this->type));

    return display_node;
}

QStandardItem* AssingNode::optimize(){
    QStandardItem* display_node = new QStandardItem("Assingment");

    display_node->appendRow(new QStandardItem(this->var->id));

    display_node->appendRow(this->expr->optimize());

    return display_node;
}

QStandardItem* StringExp::optimize(){
    QStandardItem* display_node = new QStandardItem("String");
    display_node->appendRow(new QStandardItem(this->value));
    return display_node;
}

QStandardItem* HTML_TagExp::optimize(){
    QStandardItem* display_node = new QStandardItem("HTML_Tag");
    if(!allTags.contains(this->value)){
        this->value = "";
    }
    display_node->appendRow(new QStandardItem(this->value));
    return display_node;
}

QStandardItem* InitialiseNode::optimize(){
    QStandardItem* display_node = new QStandardItem("Initialisation");

    display_node->appendRow(this->dec->optimize());
    display_node->appendRow(this->expr->optimize());

    return display_node;
}

QStandardItem* FunctionBExp::optimize(){

    QStandardItem* result1 = this->param1->optimize();
    QStandardItem* result2 = this->param2->optimize();

    if((result1->child(0)->text() == "") || (result2->child(0)->text() == "")){
        this->type = functionsB::none;
        return new QStandardItem(" \"\" optimized out (Binary function)");
    }

    QStandardItem* display_node = new QStandardItem("Binary function");
    display_node->appendRow(result1);
    display_node->appendRow(result2);

    return display_node;
}


QStandardItem* FunctionUExp::optimize(){

    QStandardItem* result = this->param->optimize();

    if (result->child(0)->text() == ""){
        this->type = functionsU::none;
        return new QStandardItem(" \"\" optimized out (Unary function)");
    }
    QStandardItem* display_node = new QStandardItem("Unary Function");
    QStandardItem* param = new QStandardItem("Parameter");
    if(this->type == functionsU::atr){
        display_node->appendRow(new QStandardItem("atr"));
    }
    if(this->type == functionsU::open){
        display_node->appendRow(new QStandardItem("open"));
    }
    if(this->type == functionsU::find_next){
        display_node->appendRow(new QStandardItem("find_next"));
    }

    display_node->appendRow(param);
    param->appendRow(result);
    return display_node;
}

QStandardItem* IfStm::optimize(){

    QStandardItem* result = this->condition->optimize();
    if( result->text() == "String"){
        if(result->child(0)->text() == "false" ||  result->child(0)->text() == ""){
            this->alwaysFalse = true;
            return nullptr;
        } else if (result->child(0)->text() == "true") {
            this->alwaysTrue = true;
            return this->body->optimize();
        } else {
        //error
        }
    }

    QStandardItem* display_node = new QStandardItem("IF");

    display_node->appendRow(result);
    display_node->appendRow(this->body->optimize());

    return display_node;
}

QStandardItem* WhileStm::optimize(){

    QStandardItem* result = this->condition->optimize();
    if( result->text() == "String"){
        if(result->child(0)->text() == "false" ||  result->child(0)->text() == ""){
            this->alwaysFalse = true;
            return nullptr;
        } else if (result->child(0)->text() == "true") {
            this->alwaysTrue = true;
        } else {
        //error
        }
    }

    QStandardItem* display_node = new QStandardItem("WHILE");

    display_node->appendRow(result);
    display_node->appendRow(this->body->optimize());

    return display_node;

}

QStandardItem* CurlBracStm::optimize(){

    QStandardItem* display_node = new QStandardItem("Body");

    for(int i = 0; i < this->body.size(); ++i){
        display_node->appendRow(this->body[i]->optimize());
    }
    return  display_node;
}

QStandardItem* VariableExp::optimize(){
    QStandardItem* display_node = new QStandardItem("Variable");
    display_node->appendRow(new QStandardItem(this->id));
    return display_node;
}
