#include "playersingleton.h"
#include <QMap>
#include <QVector>

PlayerSingleton::PlayerSingleton()
{
    health = 100;
}

void PlayerSingleton::notify()
{
    for(int i = 0; i < observers.size(); ++i){
        observers[i]->update();
    }
}

void PlayerSingleton::attachObserver(Observer *obs)
{
    observers.push_back(obs);

}

void PlayerSingleton::detachObserver(Observer *obs)
{
    observers.removeAll(obs);
}

vector<int> PlayerSingleton::getAmounts() const
{
    return amounts;
}

void PlayerSingleton::getState(Memento * state)
{
    state->setPlayer(health, items,amounts);
}

void PlayerSingleton::restoreState(Memento *mem)
{
    health = mem->getHealth();
    this->items = mem->getItems();
    this->amounts = mem->getAmounts();
}

vector<Items> PlayerSingleton::getItems() const
{
    return items;
}

PlayerSingleton* PlayerSingleton::PlayerInstance = nullptr;

PlayerSingleton*  PlayerSingleton::GetInstance(){
        if(PlayerInstance == nullptr){
            PlayerInstance = new PlayerSingleton();
        }
        return PlayerInstance;
}

void PlayerSingleton::addItems(map<Items, int> add)
{
    QMap<Items, int> qmap(add);
    for(int i = 0; i < qmap.size(); ++i){
        bool what = true;
        Items item = qmap.begin().key();
        for (int j = 0;j < this->items.size(); ++j) {
            if(this->items[j] == item){
                this->amounts[j] += qmap[item];
                what = false;
                break;
            }
        }
        if(what){
            items.push_back(item);
            amounts.push_back(qmap[item]);
        }
     qmap.remove(item);

    }
    notify();
}
