#include "observer.h"
#include "proxy.h"
#include "playersingleton.h"
MapObserver::MapObserver(QTableWidget *_table, QLabel *_label)
{
    table = _table;
    label = _label;
}

void MapObserver::update()
{
    Proxy map;
    map.loadMap(table, label);
}

InventoryObserver::InventoryObserver(QTableWidget *_table)
{
    table = _table;
}

void InventoryObserver::update()
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
