#include "proxy.h"
#include "statussingleton.h"
vector<Map*> Proxy::maps = {nullptr,nullptr, nullptr, nullptr,     nullptr, nullptr};
//enum class Locations     {house,  plaines, forest,  deep_forest, lake,    mountain};

Memento Proxy::getState()
{
    Memento  state;
    for(int i = 0; i < 6; ++i){
        if(maps[i] == nullptr){
            state.setMap(i, -1, -1);
            continue;
        } else {
            state.setMap(i, maps[i]->resourses.size(), maps[i]->enemies.size());
        }
    }
    return state;
}

void Proxy::restoreState(Memento mem)
{
     vector<int> enemies = mem.getEnemies6();
     vector<int> resourses = mem.getResourses6();
     maps = {nullptr,nullptr, nullptr, nullptr,     nullptr, nullptr};
     for(int i = 0; i < 6; ++i){
         if(enemies[i] < 0){
             continue;
         } else {
             Builder* builder = nullptr;
             switch (i) {
             case(0):{
                 builder = new HouseMapBuilder;
                 break;

             }
             case(1):{
                 builder = new PlainsMapBuilder;
                 break;

             }
             case(2):{
                 builder = new ForestMapBuilder;
                 break;

             }
             case(3):{
                 builder = new DeepForestMapBuilder;
                 break;

             }
             case(4):{
                 builder = new LakeMapBuilder;
                 break;

             }
             case(5):{
                 builder = new MountainMapBuilder;
                 break;

             }
             }
             Director director;
             director.setBuilder(builder);
             director.constructMap(enemies[i], resourses[i]);
             maps[i] = director.getMap();
         }

     }

}

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
        director.constructMap(-1, -1);
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
