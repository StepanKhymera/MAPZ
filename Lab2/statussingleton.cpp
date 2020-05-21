#include "statussingleton.h"
#include "mainwindow.h"
StatusSingleton::StatusSingleton()
{
    x = 0;
    y = 0;
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
}
