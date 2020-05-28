

#include "memento.h"
#include "proxy.h"
#include "playersingleton.h"
#include "qdebug.h"
#include "statussingleton.h"
Caretaker::Caretaker()
{

}

void Caretaker::save()
{
    Memento newMemento = Proxy::getState();
    PlayerSingleton::GetInstance()->getState(&newMemento);

    std::ofstream os("out.cereal", std::ios::binary);
     cereal::BinaryOutputArchive archive( os );
     archive( newMemento );
}

void Caretaker::load()
{
    std::ifstream os("out.cereal", std::ios::binary);
     cereal::BinaryInputArchive archive( os );
     Memento newMemento;
     archive( newMemento );

     Proxy::restoreState(newMemento);
     PlayerSingleton::GetInstance()->restoreState(&newMemento);
     StatusSingleton* ss = StatusSingleton::GetInstance();
     ss->move(ss->getX()*(-1), ss->getY()*(-1));
}

vector<int> Memento::getResourses6() const
{
    return resourses6;
}

vector<int> Memento::getEnemies6() const
{
    return enemies6;
}

int Memento::getHealth() const
{
    return health;
}

vector<Items> Memento::getItems() const
{
    return items;
}

vector<int> Memento::getAmounts() const
{
    return amounts;
}

Memento::Memento()
{
    resourses6 = {0,0,0,0,0,0};
    enemies6 = {0,0,0,0,0,0};
}

void Memento::setMap(int m, int res, int enem)
{
    if(m >5){
        qDebug() << "setMap was given " << m;
        exit(0);
    } else {
        enemies6[m] = enem;
        resourses6[m] = res;
    }
}

void Memento::setPlayer(int h, vector<Items> itm, vector<int> amou)
{
    health = h;
    items = itm;
    amounts = amou;
}
