#ifndef COMMAND_H
#define COMMAND_H

#include "memento.h"
#include "qstack.h"
#include "proxy.h"
#include "playersingleton.h"
#include "statussingleton.h"
class Server{

public:
    Server();
    QStack<QString> stack;
    int backupcount;
    void receive(QString);
    QString pop();
};

class Command
{
public:
    Command();
    virtual void Execute() = 0;

};

class BackUpCommand: public Command{
public:
    Server* serverAdress;
    BackUpCommand(Server* serverAdress);
    void Execute() override;
};

class RollBackCommand: public Command{
public:
    Server* serverAdress;
    RollBackCommand(Server* serverAdress);
    void Execute() override;
};



#endif // COMMAND_H
