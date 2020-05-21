#include "executer.h"

Executer::Executer()
{

}

void Executer::ExecuteAll(){
    table;

    while(!tree.isEmpty()){

        tree.takeFirst()->execute(table);

    }
}
