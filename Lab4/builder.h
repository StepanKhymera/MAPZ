#ifndef BUILDER_H
#define BUILDER_H

#include <QTableWidget>

#include "entity.h"
#include "abstractgen.h"
#include "strategy.h"
class Map{
public:

    AbstractGen* contentGen;

    string background;
    string frontground;
    string music;
    int lightlevel;
    int difficulty10;
    Locations location;

    vector<Resourse*> resourses;
    vector<Enemy*> enemies;

    void spawn_content();
    void load_Map(QTableWidget* table, QLabel*);


};

class Builder
{
protected:
    Map* map;

public:
    static SpawnStrategy* strategy;
    static void setStrategy(SpawnStrategy* str);
    void CreateNewMap();
    Map *getMap() const;
    virtual ~Builder();

    virtual void SetLocation() const = 0;
    virtual void SetBackground() const = 0;
    virtual void SetFrontground() const = 0;
    virtual void SetMusic() const = 0;
    virtual void SetDifficulty() const = 0;
    virtual void SetContentGen() const = 0;

    void SpawnContent(int e, int r);
};

class Director{
    Builder* builder;
public:
    void setBuilder(Builder *value);
    Map *getMap() const;
    void constructMap(int e, int r);
};


class HouseMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::house;
    }
    void SetBackground() const override{
        map->background = "House.png";
    }
    void SetFrontground() const override{
        map->frontground = "HouseOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new HouseGen;
    }
    void SetMusic() const override{
        map->music = "CalmTunes42.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 0;
    }
};

class ForestMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::forest;
    }
    void SetBackground() const override{
        map->background = "Forest.png";
    }
    void SetFrontground() const override{
        map->frontground = "ForestOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new ForestGen;
    }
    void SetMusic() const override{
        map->music = "Action-Battle-12.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 5;
    }
};

class DeepForestMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::deep_forest;
    }
    void SetBackground() const override{
        map->background = "DeepForest.png";
    }
    void SetFrontground() const override{
        map->frontground = "ForestOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new DeepForestGen;
    }
    void SetMusic() const override{
        map->music = "Action-Battle-12.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 4;
    }
};

class MountainMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::mountain;
    }
    void SetBackground() const override{
        map->background = "Mountain.png";
    }
    void SetFrontground() const override{
        map->frontground = "ForestOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new MonutainsGen;
    }
    void SetMusic() const override{
        map->music = "Action-Battle-12.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 3;
    }
};

class PlainsMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::plaines;
    }
    void SetBackground() const override{
        map->background = "Plains.png";
    }
    void SetFrontground() const override{
        map->frontground = "ForestOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new PlainesGenn;
    }
    void SetMusic() const override{
        map->music = "Action-Battle-12.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 4;
    }
};

class LakeMapBuilder: public Builder{
    void SetLocation() const override{
        map->location = Locations::lake;
    }
    void SetBackground() const override{
        map->background = "Lake.png";
    }
    void SetFrontground() const override{
        map->frontground = "ForestOverlay.png";
    }
    void SetContentGen() const override{
        map->contentGen = new LakeGen;
    }
    void SetMusic() const override{
        map->music = "Action-Battle-12.mp3";
    }
    void SetDifficulty() const override{
        map->difficulty10 = 6;
    }
};




#endif // BUILDER_H
