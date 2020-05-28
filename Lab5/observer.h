#ifndef OBSERVER_H
#define OBSERVER_H

#include <QLabel>
#include <QTableWidget>

class Observer{
public:
    virtual void update() = 0;
};

class MapObserver: public Observer
{
    QTableWidget * table;
    QLabel* label;
public:
    MapObserver(QTableWidget * table, QLabel* label);
    void update() override;
};


class InventoryObserver: public Observer
{
    QTableWidget * table;
public:
    InventoryObserver(QTableWidget * table);
    void update() override;
};


#endif // OBSERVER_H
