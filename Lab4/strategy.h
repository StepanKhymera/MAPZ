#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "enemy.h"
#include "resourse.h"
#include "abstractgen.h"
class SpawnStrategy
{
public:
    SpawnStrategy();
    virtual vector<Enemy*> spawnEnemies(AbstractGen* contentGen , int) const = 0;
    virtual vector<Resourse*> spawnResourses(AbstractGen* contentGen) const = 0;
};

class PeacefullSpawnStrategy: public SpawnStrategy{
    vector<Enemy*> spawnEnemies(AbstractGen* contentGen , int) const override;
    vector<Resourse*> spawnResourses(AbstractGen* contentGen ) const override;
};

class EasySpawnStrategy: public SpawnStrategy{
    vector<Enemy*> spawnEnemies(AbstractGen* contentGen , int) const override;
    vector<Resourse*> spawnResourses(AbstractGen* contentGen ) const override;
};

class MediumSpawnStrategy: public SpawnStrategy{
    vector<Enemy*> spawnEnemies(AbstractGen* contentGen , int) const override;
    vector<Resourse*> spawnResourses(AbstractGen* contentGen) const override;
};

class HardSpawnStrategy: public SpawnStrategy{
    vector<Enemy*> spawnEnemies(AbstractGen* contentGen , int) const override;
    vector<Resourse*> spawnResourses(AbstractGen* contentGen) const override;
};


#endif // STRATEGY_H
