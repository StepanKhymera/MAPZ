#ifndef ABSTRACTGEN_H
#define ABSTRACTGEN_H

#include "enemy.h"
#include "resourse.h"
class AbstractGen
{
public:
     AbstractGen();
  virtual Enemy *CreateEnemy() const = 0;
  virtual Resourse *CreateResourse() const = 0;
};

class HouseGen: public AbstractGen{
    Enemy *CreateEnemy() const override;
    Resourse *CreateResourse() const override;
};

class ForestGen: public AbstractGen{
    Enemy *CreateEnemy() const override;
    Resourse *CreateResourse() const override;
};

class DeepForestGen: public AbstractGen{
    Enemy *CreateEnemy() const override;
    Resourse *CreateResourse() const override{
        return new BlueLeaf;
    }
};

class MonutainsGen: public AbstractGen{
    Enemy *CreateEnemy() const override{
        return new Golem;
    }
    Resourse *CreateResourse() const override{
        return new RedLeaf;
    }
};

class PlainesGenn: public AbstractGen{
    Enemy *CreateEnemy() const override{
        return new Shaman;
    }
    Resourse *CreateResourse() const override{
        return new YellowLeaf;
    }
};

class LakeGen: public AbstractGen{
    Enemy *CreateEnemy() const override{
        return new Skeleton;
    }
    Resourse *CreateResourse() const override{
        return new PurpleLeaf;
    }
};

#endif // ABSTRACTGEN_H
