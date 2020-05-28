#include "statussingleton.h"
#include "mainwindow.h"
StatusSingleton::StatusSingleton()
{
    x = 0;
    y = 0;
}

void StatusSingleton::notify()
{
    for(int i = 0; i < observers.size(); ++i){
        observers[i]->update();
    }
}

void StatusSingleton::attachObserver(Observer *obs)
{
    observers.push_back(obs);
}

void StatusSingleton::detachObserver(Observer *obs)
{
   observers.removeAll(obs);
}

Map *StatusSingleton::getMap() const
{
    return map;
}

void StatusSingleton::setMap(Map *value)
{
    map = value;
}

int StatusSingleton::getY() const
{
    return y;
}

int StatusSingleton::getX() const
{
    return x;
}


StatusSingleton* StatusSingleton::StatusInstance = nullptr;

StatusSingleton *StatusSingleton::GetInstance()
{
    WaitForSingleObject(hMutex, INFINITE);

    if(StatusInstance == nullptr){
        StatusInstance = new StatusSingleton();
    }

    ReleaseMutex(hMutex);

    return StatusInstance;

}

void StatusSingleton::move(int Dx, int Dy){
    x += Dx;
    y += Dy;
    notify();
}
