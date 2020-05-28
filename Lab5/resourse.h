#ifndef RESOURSE_H
#define RESOURSE_H

#include "serialization.h"
#include "entity.h"
#include "Enums.h"

class Resourse
{
protected:
    int32_t id;

    Items loots;
    int amounts;
    Buff* on_harvest;
    int exp;
    string texure;
public:
    Buff* on_interactin();
    map<Items, int> harvest();
    Resourse();
    string getTexure() const;
    int getAmounts() const;
    Items getLoots() const;
    template <class Archive>
    void save( Archive & ar ) const
    {
      ar(loots);
    }

    template <class Archive>
    void load( Archive & ar )
    {
      static int32_t idGen = 0;
      id = idGen++;
      ar( loots );
    }
};


class RedLeaf: public Resourse{
    public:
    RedLeaf();
};

class BlueLeaf: public Resourse{
    public:
    BlueLeaf();
};

class YellowLeaf: public Resourse{
    public:
    YellowLeaf();
};

class GreenLeaf: public Resourse{
    public:
    GreenLeaf();
};

class OrangeLeaf: public Resourse{
    public:
    OrangeLeaf();
};

class PurpleLeaf: public Resourse{
    public:
    PurpleLeaf();
};

#endif // RESOURSE_H
