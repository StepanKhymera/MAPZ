#ifndef MEMENTO_H
#define MEMENTO_H
#include "serialization.h"
#include <memory>
#include <fstream>
#include "builder.h"

class Caretaker
{
public:
    Caretaker();
    void save();
    void load();
};

class Memento{
    vector<int> resourses6;
    vector<int> enemies6;
    int health;
    vector<Items> items;
    vector<int> amounts;

public:
    Memento();
    int32_t id;
    template <class Archive>
    void save( Archive & ar ) const
    {
      ar( health, items, amounts, resourses6, enemies6);
    }
    template <class Archive>
    void load( Archive & ar )
    {
      static int32_t idGen = 0;
      id = idGen++;
      ar( health, items, amounts, resourses6, enemies6);
    }

    void setMap(int m, int res, int enem);
    void setPlayer(int h, vector<Items> itm, vector<int> amou);

    vector<int> getResourses6() const;
    vector<int> getEnemies6() const;
    int getHealth() const;
    vector<Items> getItems() const;
    vector<int> getAmounts() const;
};

#endif // MEMENTO_H
