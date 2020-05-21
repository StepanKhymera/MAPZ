#ifndef STATUSSINGLETON_H
#define STATUSSINGLETON_H

#include "entity.h"
#include "builder.h"

class StatusSingleton
{
private:
    StatusSingleton();
    static StatusSingleton* StatusInstance;
    int x;
    int y;
    Map* map;
public:
    static StatusSingleton* GetInstance();
    void move(int Dx, int Dy);
    int getX() const;
    int getY() const;
    void setMap(Map *value);
    Map *getMap() const;
};

#endif // STATUSSINGLETON_H
