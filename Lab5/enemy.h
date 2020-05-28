#ifndef ENEMY_H
#define ENEMY_H

#include "serialization.h"

#include "entity.h"
#include "Enums.h"
#include <vector>
#include <QLabel>
#include <QMap>
//#include "me
using namespace std;

class Flyweight;
class Flyweight{
public:
    QPixmap* texure;
    int maxHealth;
    int maxStamina;
    int attack_radius;
    bool drop_on_damage;
    int strenght;

    Monsters type;
    vector<Items> loot;
};
class Enemy: public Entity
{
protected:
    int experience;
    int level;
    int current_strenght;
    Flyweight* flyweight;
public:
    Enemy();
    void get_hit(int);
    int attack();

    QPixmap* getTexure() const;
    Monsters getType() const;
    int getHealth() const;
    vector<Items> getLoot() const;
    void setLevel(int level, float health, float attack);
//    int32_t id;
//    template <class Archive>
//    void save( Archive & ar ) const
//    {
//      ar( flyweight->type);
//    }

//    template <class Archive>
//    void load( Archive & ar )
//    {
//      static int32_t idGen = 0;
//      id = idGen++;
//      ar( flyweight->type );
//    }
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
