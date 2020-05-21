#ifndef ENTITY_H
#define ENTITY_H
#include <map>
#include <list>

using namespace std;

class Buff{

};

class Entity
{
protected:
    int health;
    int stamina;
    int speed;

    list<Buff*> active_buffs;
    list<string> immunities;
public:
    Entity();
    void apply_effect(Buff*);
    //timer
};

#endif // ENTITY_H
