#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "Enums.h"
#include <vector>
#include <QLabel>
#include <QMap>
using namespace std;

class Flyweight;

class Enemy: public Entity
{
protected:
    int experience;
    int level;
    Flyweight* flyweight;
public:
    Enemy();
    void get_hit(int);
    int attack();

    QPixmap* getTexure() const;
    Monsters getType() const;
    int getHealth() const;
    vector<Items> getLoot() const;
};

class Bat: public Enemy{
public:
    Bat();
};

class Skeleton: public Enemy{
public:
    Skeleton();
};

class Ghost: public Enemy{
public:
    Ghost();
};

class Skull: public Enemy{
public:
    Skull();
};

class Shaman: public Enemy{
public:
    Shaman();
};

class Golem: public Enemy{
public:
    Golem();
};

class Flyweight{
public:
    QPixmap* texure;
    int maxHealth;
    int maxStamina;
    int attack_radius;
    int strenght;
    bool drop_on_damage;
    Monsters type;
    vector<Items> loot;
};

class FlyweightFactory{
public:
    static QMap<Monsters, Flyweight*> storage;

    static Flyweight* GetGhostFl();
    static Flyweight* GetBatFl();
    static Flyweight *GetSkeletonFl();
    static Flyweight* GetShamanFl();
    static Flyweight* GetGolemFl();
    static Flyweight *GetSkullFl();
};
#endif // ENEMY_H
