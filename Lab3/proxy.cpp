#include "proxy.h"
#include "statussingleton.h"
vector<Map*> Proxy::maps = {nullptr,nullptr, nullptr, nullptr,     nullptr, nullptr};
//enum class Locations     {house,  plaines, forest,  deep_forest, lake,    mountain};

void Proxy::loadMap(QTableWidget * table, QLabel * label)
{
    label->setText("<img src='C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Background\\" + QString::fromStdString(background) + "' width= 481 height= 361 >");

    int x = StatusSingleton::GetInstance()->getX();
    int y = StatusSingleton::GetInstance()->getY();
    Builder* builder = nullptr;
    int lock = -1;
    switch (x) {
    case(1):{
        if(maps[4] == nullptr){
            builder = new LakeMapBuilder;
        }
        lock = 4;
        break;
    }
    case(0):{
        switch (y) {
        case(1):{
            if(maps[5] == nullptr){
                builder = new MountainMapBuilder;
            }
            lock = 5;
            break;
        }
        case(0):{
            if(maps[0] == nullptr){
                builder = new HouseMapBuilder;
            }
            lock = 0;
            break;
        }
        case(-1):{
            if(maps[1] == nullptr){
                builder = new PlainsMapBuilder;
            }
            lock = 1;
            break;
        }
        }
        break;
    }
    case(-1):{
        if(maps[2] == nullptr){
            builder = new ForestMapBuilder;
        }
        lock = 2;
        break;
    }
    case(-2):{
        if(maps[3] == nullptr){
            builder = new DeepForestMapBuilder;
        }
        lock = 3;
        break;
    }
    }
    if(builder != nullptr){
        Director director;
        director.setBuilder(builder);
        director.constructMap();
        Map* map = director.getMap();
        maps[lock] = map;
    }
    StatusSingleton::GetInstance()->setMap( maps[lock]);

    maps[lock]->load_Map(table,label );

}

Proxy::Proxy()
{
    this->background = "LoadingScreen.png";
    this->music = "Loading.mp3";
}
