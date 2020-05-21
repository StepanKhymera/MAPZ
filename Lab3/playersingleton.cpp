#include "playersingleton.h"

PlayerSingleton::PlayerSingleton()
{

}

vector<int> PlayerSingleton::getAmounts() const
{
    return amounts;
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
#include <QMap>
#include <QVector>
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
}
