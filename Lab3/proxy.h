#ifndef PROXY_H
#define PROXY_H

#include "builder.h"

class Proxy: public Map
{
public:
    static vector<Map*> maps;
    void loadMap(QTableWidget*, QLabel*);
    Proxy();
};

#endif // PROXY_H
