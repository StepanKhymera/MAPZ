#ifndef FACADE_H
#define FACADE_H
#include <QTableWidget>
#include <QLabel>
class Facade
{
public:
    Facade();
    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    void consume(int row);
    void updateInventory(QTableWidget*);
    void updateMap(QTableWidget*, QLabel*);
};

#endif // FACADE_H
