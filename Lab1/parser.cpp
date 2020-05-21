#include "parser.h"
#include <iostream>

Parser::Parser()
{

}


void Parser::parse(){

    QStandardItem* tree_root = new QStandardItem("HEAD");

    for(int i = 0; i < tokens.size(); ++i){
        QStandardItem* display_node = new QStandardItem();
        tree_root->appendRow(display_node);
        display_node_run = display_node;
        line = tokens[i];

        if(line[0]->tag == "var_type"){
            if( line.size() > 2){
                display_node->setText("Initialise");
                tree.append(parseInitialise());

            } else {
                display_node->setText("Declaration");
                this->tree.append(parseDeclaration());
            }
        }
        if(line[0]->tag == "identifier"){
            display_node->setText("Assing");

            this->tree.append(parseAssingNode());
        }

        if(line[0]->tag == "functionU"){
            display_node->setText("Unary function");

            tree.append(parseFunctionU(0));
        }

        if(line[0]->tag == "functionB"){
            display_node->setText("Binary function");

            tree.append(parseFunctionB(0));
        }
        if(line[0]->value == "if"){
            display_node->setText("IF");
            tree.append(parseIfStm(&i));
        }
        if(line[0]->value == "while"){
            display_node->setText("While");
            tree.append(parseWhileStm(&i));
        }
        if(line[0]->value == "keyword"){

        }
    }
    model_raw->appendRow(tree_root);

}

DeclarationNode* Parser::parseDeclaration(){
    DeclarationNode* new_node = new DeclarationNode;

    display_node_run->appendRow(new QStandardItem(line[0]->value));
    display_node_run->appendRow(new QStandardItem(line[1]->value));

    new_node->type = line[0]->value;
    new_node->id = line[1]->value;
    return new_node;
}

InitialiseNode* Parser::parseInitialise(){
    InitialiseNode* new_node = new InitialiseNode;

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem("Declaration");
    QStandardItem* right = new QStandardItem("Expression");

    save->appendRow(left);
    save->appendRow(right);

    display_node_run = left;
    new_node->dec = parseDeclaration();
    display_node_run = save;

    display_node_run = right;
    new_node->expr = parseExpresion(3);
    display_node_run = save;

    return new_node;
}

AssingNode* Parser::parseAssingNode(){
    AssingNode* new_node = new AssingNode;

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem(line[0]->value);
    QStandardItem* right = new QStandardItem("Expression");

    save->appendRow(left);
    save->appendRow(right);

    new_node->var = new VariableExp(line[0]->value);

    display_node_run = right;
    new_node->expr = parseExpresion(2); //HARDCODE
    display_node_run = save;

    return new_node;
}


Expression* Parser::parseExpresion(int start){

    if(line[start]->tag == "identifier"){
        QStandardItem* row;


        row = new QStandardItem("Variable");


        display_node_run->appendRow(row);


        row->appendRow(new QStandardItem(line[start]->value));
        VariableExp* new_node = new VariableExp(line[start]->value);
        return new_node;
    }
    if(line[start]->tag == "dquotes"){

        QString string = line[start]->value;
        if(line[start]->value[line[start]->value.size()-1] != "\""){
            while(true){
                string += line[++start]->value;
                if(line[start]->value[line[start]->value.size()-1] == "\"") break;
            }
        }
        StringExp* new_node = new StringExp(string);

        QStandardItem* row = new QStandardItem("String");
        display_node_run->appendRow(row);
        row->appendRow(new QStandardItem(string));

        return new_node;
    }
    if(line[start]->tag == "functionU"){
        QStandardItem* row = new QStandardItem("Unary function");
        display_node_run->appendRow(row);
        display_node_run = row;

        return parseFunctionU(start);
    }

    if(line[start]->tag == "functionB"){
        QStandardItem* row = new QStandardItem("Binary function");
        display_node_run->appendRow(row);
        display_node_run = row;

        return parseFunctionB(start);
    }
    if(line[start]->tag == "HTML_tag"){
        QString string = line[start]->value;
        if(line[start]->value[line[start]->value.size()-1] != ">"){
            while(true){
                string += line[++start]->value;
                if(line[start]->value[line[start]->value.size()-1] == ">") break;
            }
        }

        QStandardItem* row;
        row = new QStandardItem("HTML_tag");
        display_node_run->appendRow(row);
        row->appendRow(new QStandardItem(string));

        HTML_TagExp* new_node = new HTML_TagExp(string);

        return new_node;
    }

    if(line[start]->tag == "keyword"){
        QStandardItem* row = new QStandardItem("Keyword");
        StringExp* new_node = new StringExp(line[start]->value);

        display_node_run->appendRow(row);
        row->appendRow(new QStandardItem(line[start]->value));

        return new_node;
    }

}

FunctionUExp* Parser::parseFunctionU(int start){
    FunctionUExp* new_node = new FunctionUExp;

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem(line[start]->value);
    QStandardItem* right = new QStandardItem("Expression");

    save->appendRow(left);
    save->appendRow(right);

    new_node->type = convert_typeU(start);

    display_node_run = right;
    new_node->param = parseExpresion(start +1);


    return new_node;
}

FunctionBExp* Parser::parseFunctionB(int start){
    FunctionBExp* new_node = new FunctionBExp;
    new_node->type = convert_typeB(start);

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem("Expression param 1");
    QStandardItem* right = new QStandardItem("Expression param 2");

    save->appendRow(left);
    save->appendRow(right);

    display_node_run = left;
    new_node->param1 = parseExpresion(start +1);
    display_node_run = save;

    display_node_run = right;
    new_node->param2 = parseExpresion(start +3); //HARDCODE
    display_node_run = save;

    return  new_node;
}

IfStm* Parser::parseIfStm(int* i){
    IfStm* new_node = new IfStm;

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem("Condition Expression");
    QStandardItem* right = new QStandardItem("Body");

    save->appendRow(left);
    save->appendRow(right);

    display_node_run = left;
    new_node->condition = parseExpresion(2);
    display_node_run = save;

    display_node_run = right;
    new_node->body = parseCurlBracStm(i);
    display_node_run = save;

    return new_node;
}

CurlBracStm* Parser::parseCurlBracStm(int* i){
    int end = 0;
    for (int s = ++(*i); s < tokens.size(); ++s) {
        if (tokens[s][0]->tag == "closed_curl"){
            end = s;
            break;
        }
    }


    CurlBracStm* new_node = new CurlBracStm;

    QStandardItem* save = display_node_run;


    for(; *i <= end; ++(*i)){

        QStandardItem* display_node = new QStandardItem();

        save->appendRow(display_node);
        display_node_run = display_node;

        line = tokens[*i];

        if(line[0]->tag == "var_type"){
            if( line.size() > 2){
                display_node->setText("Initialise");
                new_node->body.append(parseInitialise());

            } else {
                display_node->setText("Declaration");
                new_node->body.append(parseDeclaration());
            }
        }
        if(line[0]->tag == "identifier"){
            display_node->setText("Assing");

            new_node->body.append(parseAssingNode());
        }

        if(line[0]->tag == "functionU"){
            display_node->setText("Unary function");

            new_node->body.append(parseFunctionU(0));
        }

        if(line[0]->tag == "functionB"){
            display_node->setText("Binary function");

            new_node->body.append(parseFunctionB(0));
        }
        if(line[0]->value == "if"){
            display_node->setText("IF");
            new_node->body.append(parseIfStm(i));
        }
        if(line[0]->value == "while"){
            display_node->setText("WHILE");
            new_node->body.append(parseWhileStm(i));
        }
    }
    return new_node;
}

WhileStm* Parser::parseWhileStm(int* i){

    WhileStm* new_node = new WhileStm;

    QStandardItem* save = display_node_run;

    QStandardItem* left = new QStandardItem("Condition Expression");
    QStandardItem* right = new QStandardItem("Body");

    save->appendRow(left);
    save->appendRow(right);

    display_node_run = left;
    new_node->condition = parseExpresion(2);
    display_node_run = save;

    display_node_run = right;
    new_node->body = parseCurlBracStm(i);
    display_node_run = save;

    return new_node;
}

functionsU Parser::convert_typeU(int start){
    if(line[start]->value == "open"){
        return functionsU::open;
    }
    if(line[start]->value == "atr"){
        return functionsU::atr;
    }
    if(line[start]->value == "find_next"){
        return functionsU::find_next;
    }

}

functionsB Parser::convert_typeB(int start){
    if(line[start]->value == "find_f"){
        return functionsB::find_f;
    }
    if(line[start]->value == "find_all"){
        return functionsB::find_all;
    }
}
void Parser::optimize(){
    QStandardItem* display_node = new QStandardItem("OHEAD");

    for(int i = 0; i < tree.size(); ++i){
        display_node->appendRow(tree[i]->optimize());
    }

    model_optimized->appendRow(display_node);
}
