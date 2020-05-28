#ifndef STATUSSINGLETON_H
#define STATUSSINGLETON_H

#include "entity.h"
#include "builder.h"
#include "observer.h"

#include <QVector>
class StatusSingleton
{
private:
    StatusSingleton();
    static StatusSingleton* StatusInstance;
    int x;
    int y;
    Map* map;

    QVector<Observer*> observers;
    void notify();
public:
    void attachObserver(Observer* obs);
    void detachObserver(Observer* obs);

    static StatusSingleton* GetInstance();
    void move(int Dx, int Dy);
    int getX() const;
    int getY() const;
    void setMap(Map *value);
    Map *getMap() const;
};

#endif // STATUSSINGLETON_H
