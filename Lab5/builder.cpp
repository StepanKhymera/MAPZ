#include "builder.h"
#include "statussingleton.h"

#include <QTableWidgetItem>
# include <QLabel>

SpawnStrategy* Builder::strategy = new MediumSpawnStrategy;

Map *Builder::getMap() const
{
    return map;
}

Builder::~Builder(){}

void Builder::SpawnContent(int e, int r)
{
    if(e < 0 && r < 0){
      map->enemies = strategy->spawnEnemies(map->contentGen, map->difficulty10);
      map->resourses = strategy->spawnResourses(map->contentGen);

    } else {
        if(map->contentGen == nullptr) return;
        if (this->map->difficulty10 > 0){
            int rand_enemies = e; //1-difficulty
            for(int i = 0; i < rand_enemies; ++i){
                Enemy* run(map->contentGen->CreateEnemy());
                if(run == nullptr) break;
                map->enemies.push_back(run);
            }
        }
        int rand_resourses = r; //1-5
        for(int i = 0; i < rand_resourses; ++i){
              Resourse* run(map->contentGen->CreateResourse());
            map->resourses.push_back(run) ;
        }
    }
}

void Builder::setStrategy(SpawnStrategy *str)
{
    strategy = str;
}

void Builder::CreateNewMap()
{
    map = new Map();
}

//Builder::Builder()
//{

//}
void Map::load_Map(QTableWidget* table, QLabel* label)
{
     label->setText("<img src='C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Background\\" + QString::fromStdString(background) + "' width= 481 height= 361 >");

    table->setRowCount(this->enemies.size()+this->resourses.size());

    int e;
    for(e = 0; e < this->enemies.size(); ++e){

        QPixmap* icon = this->enemies[e]->getTexure();
        QLabel* label = new QLabel;
        label->setPixmap(*icon);
        label->setAlignment(Qt::AlignCenter);

        table->setCellWidget(e, 0, label);
        QString name = QString::fromStdString(string(MonsterStrings[static_cast<int>(this->enemies[e]->getType())]));
        table->setItem(e, 1, new QTableWidgetItem(name));
        int h = this->enemies[e]->getHealth();
        table->setItem(e, 2, new QTableWidgetItem(QString::number(h)));
    }

    for(int i = 0; i < this->resourses.size(); ++i){
        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Items\\" + QString::fromStdString(this->resourses[i]->getTexure()));
        QPixmap resPix = pix.scaled(20,20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        QLabel *icon = new QLabel;
        icon->setPixmap(resPix);
        icon->setAlignment(Qt::AlignCenter);
        table->setCellWidget(i+e, 0, icon);
        QString name = QString::fromStdString(this->resourses[i]->getTexure());
        name.chop(4);
        table->setItem(i+e, 1, new QTableWidgetItem(name));
        table->setItem(i+e, 2, new QTableWidgetItem(QString::number(this->resourses[i]->getAmounts())));
    }
}


Map *Director::getMap() const
{
    return builder->getMap();
}

void Director::constructMap(int e, int r)
{
    this->builder->CreateNewMap();
      this->builder->SetLocation() ;
       this->builder->SetBackground() ;
       this->builder->SetFrontground() ;
      this->builder-> SetMusic() ;
      this->builder-> SetDifficulty() ;
       this->builder->SetContentGen() ;
     this->builder->SpawnContent(e, r);
}

void Director::setBuilder(Builder *value)
{
    builder = value;
}
