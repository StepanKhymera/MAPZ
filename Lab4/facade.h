#ifndef FACADE_H
#define FACADE_H
#include <QTableWidget>
#include <QLabel>
#include <memento.h>
#include "command.h"
class Facade
{
private:
    Caretaker caretaker;
    BackUpCommand* backup;
    RollBackCommand *rollback;
public:
    Facade(QTableWidget * table, QLabel* label, QTableWidget* table2);
    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    void consume(int row);
    void updateInventory(QTableWidget*);
    void updateMap(QTableWidget*, QLabel*);

    void save();
    void load();

    void setDifficultyPeacefull();
    void setDifficultyEasy();
    void setDifficultyMedium();
    void setDifficultyHard();

    void restartDay();

    void saveToServer();
    void loadFromServer();
};

#endif // FACADE_H
