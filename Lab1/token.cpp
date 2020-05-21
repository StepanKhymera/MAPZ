#include "token.h"


Token::Token(){

}

Token::Token(QString lexem)
{
    QList<QString> keywords = {"if","while", "in", "true", "false"};
    QList<QString> var_types = {"tag","file"};
    QList<QString> functionsU = {"open","find_next","atr"};
    QList<QString> functionsB = {"find_f","find_all"};

    value = lexem;

    if(isdigit(lexem[0].toLatin1())){
        tag = "integer";
        return;
    }

    if(isalpha(lexem[0].toLatin1())){
        if(keywords.contains(lexem)){
            tag = "keyword";
            return;
        }
        if(functionsU.contains(lexem)){
            tag = "functionU";
            return;
        }

        if(functionsB.contains(lexem)){
            tag = "functionB";
            return;
        }

        if(var_types.contains(lexem)){
            tag = "var_type";
            return;
        }

        tag = "identifier";
        return;
    }

    switch (lexem[0].toLatin1()) {
    case('<'):{
        tag = "HTML_tag";
        return;
    }
    case('\"'):{
        tag = "dquotes";
        return;
    }
    case(','):{
        tag = "coma";
        return;
    }
    case('='):{
        tag = "is_equall";
        return;
    }
    case('('):{
        tag = "open_par";
        return;
    }
    case(')'):{
        tag = "closed_par";
        return;
    }
    case('{'):{
        tag = "open_curl";
        return;
    }
    case('}'):{
        tag = "closed_curl";
        return;
    }
    }
}
