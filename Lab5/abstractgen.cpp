#include "abstractgen.h"

AbstractGen::AbstractGen()
{

}

Enemy *DeepForestGen::CreateEnemy() const{
    return new Ghost;
}

Enemy *HouseGen::CreateEnemy() const{
    return nullptr;
}

Resourse *HouseGen::CreateResourse() const{
    return new GreenLeaf;
}

Enemy *ForestGen::CreateEnemy() const{
    return new Bat;
}

Resourse *ForestGen::CreateResourse() const{
    return new YellowLeaf;
}
