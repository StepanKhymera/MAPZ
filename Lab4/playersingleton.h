#ifndef PLAYERSINGLETON_H
#define PLAYERSINGLETON_H

#include "Enums.h"
#include "entity.h"
#include <vector>
#include "memento.h"
#include "observer.h"
using namespace std;

class PlayerSingleton: public Entity
{
private:
    PlayerSingleton();
    static PlayerSingleton* PlayerInstance;
    vector<Items> items;
    vector<int> amounts;
    map<Items, Buff*> potions_inv;

    QVector<Observer*> observers;
    void notify();
public:
    void attachObserver(Observer* obs);
    void detachObserver(Observer* obs);

    static PlayerSingleton* GetInstance();
    map<Items, Buff*> make_a_potion();
    Buff* drink_a_potion(std::map<Items, Buff*>);
    int attack();
    list<Items> interact();
    void addItems(map<Items, int>);
    vector<Items> getItems() const;
    vector<int> getAmounts() const;

    void getState(Memento*);
    void restoreState(Memento*);
};

#endif // PLAYERSINGLETON_H
