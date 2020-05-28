#include "facade.h"
#include "statussingleton.h"
#include "playersingleton.h"
#include "proxy.h"
#include "observer.h"
Facade::Facade(QTableWidget * table, QLabel* label, QTableWidget* table2)
{
    Server* serv = new Server;
    serv->backupcount = 1;
    backup = new BackUpCommand(serv);
    rollback = new RollBackCommand(serv);

    Observer* mapOb = new MapObserver(table, label);
    Observer* invOb = new InventoryObserver(table2);
    StatusSingleton::GetInstance()->attachObserver(mapOb);
    PlayerSingleton::GetInstance()->attachObserver(invOb);
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
        vector<Items> loot = curmap->enemies[row]->getLoot();
        curmap->enemies.erase(curmap->enemies.begin()+row-1);
        map<Items, int> invt;
        for(int i = 0; i < loot.size();++i){
            invt.insert(pair<Items, int>(loot[i], 1));
        }
        PlayerSingleton::GetInstance()->addItems(invt);
    } else {
//        Resourse* to_consume = curmap->resourses[row - curmap->enemies.size()];
        Items loot = curmap->resourses[row - curmap->enemies.size()]->getLoots();
        curmap->resourses.erase(curmap->resourses.begin()+row - curmap->enemies.size());
        map<Items, int> invt;
        invt.insert(pair<Items, int>(loot, curmap->resourses[row - curmap->enemies.size()]->getAmounts()));
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

void Facade::save()
{
    caretaker.save();
}

void Facade::load()
{
    caretaker.load();
}

void Facade::setDifficultyPeacefull()
{
    Builder::setStrategy(new PeacefullSpawnStrategy);
}

void Facade::setDifficultyEasy()
{
    Builder::setStrategy(new EasySpawnStrategy);
}

void Facade::setDifficultyMedium()
{
    Builder::setStrategy(new MediumSpawnStrategy);

}

void Facade::setDifficultyHard()
{
    Builder::setStrategy(new HardSpawnStrategy);

}

void Facade::restartDay()
{
    StatusSingleton* ss = StatusSingleton::GetInstance();
    ss->move(ss->getX()*(-1), ss->getY()*(-1));
    Proxy::maps = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

}

void Facade::saveToServer()
{
    backup->Execute();
}

void Facade::loadFromServer()
{
    rollback->Execute();
}
