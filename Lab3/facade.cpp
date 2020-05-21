#include "facade.h"
#include "statussingleton.h"
#include "playersingleton.h"
#include "proxy.h"
Facade::Facade()
{

}

void Facade::moveUp()
{
    StatusSingleton::GetInstance()->move(0, 1);
}

void Facade::moveRight()
{
    StatusSingleton::GetInstance()->move(1, 0);
}

void Facade::moveDown()
{
    StatusSingleton::GetInstance()->move(0, -1);
}

void Facade::moveLeft()
{
    StatusSingleton::GetInstance()->move(-1, 0);
}

void Facade::consume(int row)
{
    Map*  curmap = StatusSingleton::GetInstance()->getMap();
    if(row < curmap->enemies.size()){
        Enemy* to_consume = curmap->enemies[row];
        vector<Items> loot = to_consume->getLoot();
        curmap->enemies.erase(curmap->enemies.begin()+row-1);
        map<Items, int> invt;
        for(int i = 0; i < loot.size();++i){
            invt.insert(pair<Items, int>(loot[i], 1));
        }
        PlayerSingleton::GetInstance()->addItems(invt);
    } else {
        Resourse* to_consume = curmap->resourses[row - curmap->enemies.size()];
        Items loot = to_consume->getLoots();
        curmap->resourses.erase(curmap->resourses.begin()+row - curmap->enemies.size());
        map<Items, int> invt;
        invt.insert(pair<Items, int>(loot, to_consume->getAmounts()));
        PlayerSingleton::GetInstance()->addItems(invt);
    }

}
void Facade::updateInventory(QTableWidget * table)
{
    vector<Items> items = PlayerSingleton::GetInstance()->getItems();
    vector<int> amounts = PlayerSingleton::GetInstance()->getAmounts();

    table->setRowCount(0);
    table->setRowCount(items.size());
    for (int i = 0; i < items.size();++i) {
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(string(ItemStrings[static_cast<int>(items[i])]))));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(amounts[i])));
    }
}

void Facade::updateMap(QTableWidget * table, QLabel* label)
{
    Proxy map;
    map.loadMap(table, label);
}
