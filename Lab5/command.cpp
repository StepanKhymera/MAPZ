#include "command.h"
#include "windows.h"

Command::Command()
{

}

BackUpCommand::BackUpCommand(Server *_serverAdress)
{
    serverAdress = _serverAdress;
}

void BackUpCommand::Execute()
{
    serverAdress->receive("out.cereal");
}

RollBackCommand::RollBackCommand(Server *_serverAdress)
{
    serverAdress = _serverAdress;

}

void RollBackCommand::Execute()
{
   QString file = serverAdress->pop();

   std::ifstream os(file.toStdString(), std::ios::binary);
    cereal::BinaryInputArchive archive( os );
    Memento newMemento;
    archive( newMemento );

    Proxy::restoreState(newMemento);
    PlayerSingleton::GetInstance()->restoreState(&newMemento);
    StatusSingleton* ss = StatusSingleton::GetInstance();
    ss->move(ss->getX()*(-1), ss->getY()*(-1));
}

Server::Server()
{

}

void Server::receive(QString file)
{
    QString path = "backups\\backup" + QString::number(backupcount++) + ".cereal";
    CopyFileA(file.toUtf8(), path.toUtf8(), TRUE);
    stack.push(path);
}

QString Server::pop()
{
    return stack.pop();
}
