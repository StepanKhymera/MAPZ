#ifndef PROXY_H
#define PROXY_H

#include "builder.h"
#include "memento.h"
class Proxy: public Map
{
public:
    static vector<Map*> maps;
    static Memento getState();
    static void restoreState(Memento mem);
    void loadMap(QTableWidget*, QLabel*);
    Proxy();
};

#endif // PROXY_H
