#include "strategy.h"

SpawnStrategy::SpawnStrategy()
{

}

vector<Enemy*> PeacefullSpawnStrategy::spawnEnemies(AbstractGen * contentGen, int) const
{
    return vector<Enemy*>();
}
vector<Resourse*> PeacefullSpawnStrategy::spawnResourses(AbstractGen *contentGen) const
{
    vector<Resourse*> resourses;

    int rand_resourses = rand()%4 + 3; //3-6
    for(int i = 0; i < rand_resourses; ++i){
        Resourse* run(contentGen->CreateResourse());
        resourses.push_back(run) ;
    }
    return  resourses;
}

vector<Enemy*> EasySpawnStrategy::spawnEnemies(AbstractGen *contentGen, int difficulty10) const
{

    if(contentGen == nullptr) vector<Enemy*>();
    vector<Enemy*> enemies;
    if (difficulty10 > 0){
        int rand_enemies = rand()%difficulty10 + 2; //2-difficulty
        for(int i = 0; i < rand_enemies; ++i){
            Enemy* run(contentGen->CreateEnemy());
            run->setLevel(1, 0.4, 0.5); // 40% Health, 50% Strenght
            if(run == nullptr) break;
            enemies.push_back(run);
        }
    }
    return enemies;
}

vector<Resourse*> EasySpawnStrategy::spawnResourses(AbstractGen *contentGen) const
{
    vector<Resourse*> resourses;

    int rand_resourses = rand()%4 + 3; //3-6
    for(int i = 0; i < rand_resourses; ++i){
        Resourse* run(contentGen->CreateResourse());
        resourses.push_back(run) ;
    }
    return  resourses;
}

vector<Enemy *> MediumSpawnStrategy::spawnEnemies(AbstractGen *contentGen, int difficulty10) const
{
    if(contentGen == nullptr) vector<Enemy*>();
    vector<Enemy*> enemies;
    if (difficulty10 > 0){
        int rand_enemies = rand()%difficulty10 + 2; //2-difficulty
        for(int i = 0; i < rand_enemies; ++i){
            Enemy* run(contentGen->CreateEnemy());
            run->setLevel(2, 1 , 1);  // 100% Health, 100% Strenght
            if(run == nullptr) break;
            enemies.push_back(run);
        }
    }
    return enemies;
}

vector<Resourse *> MediumSpawnStrategy::spawnResourses(AbstractGen *contentGen) const
{
    vector<Resourse*> resourses;

    int rand_resourses = rand()%3 + 1; //1-3
    for(int i = 0; i < rand_resourses; ++i){
        Resourse* run(contentGen->CreateResourse());
        resourses.push_back(run) ;
    }
    return  resourses;
}

vector<Enemy *> HardSpawnStrategy::spawnEnemies(AbstractGen *contentGen, int difficulty10) const
{
    if(contentGen == nullptr) vector<Enemy*>();
    vector<Enemy*> enemies;
    if (difficulty10 > 0){
        int rand_enemies = rand()%difficulty10 + 2; //2-difficulty
        for(int i = 0; i < rand_enemies; ++i){
            Enemy* run(contentGen->CreateEnemy());
            run->setLevel(3, 1.5 , 2);  // 150% Health, 200% Strenght
            if(run == nullptr) break;
            enemies.push_back(run);
        }
    }
    return enemies;
}

vector<Resourse *> HardSpawnStrategy::spawnResourses(AbstractGen *contentGen) const
{
    vector<Resourse*> resourses;

    int rand_resourses = rand()%3; //0-2
    for(int i = 0; i < rand_resourses; ++i){
        Resourse* run(contentGen->CreateResourse());
        resourses.push_back(run) ;
    }
    return  resourses;
}
