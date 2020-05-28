#include "enemy.h"

Enemy::Enemy()
{

}

QMap<Monsters, Flyweight*> FlyweightFactory::storage;

QPixmap *Enemy::getTexure() const
{
    return flyweight->texure;
}

Monsters Enemy::getType() const
{
    return flyweight->type;
}

int Enemy::getHealth() const
{
    return health;
}

vector<Items> Enemy::getLoot() const
{
    return flyweight->loot;
}

void Enemy::setLevel(int _level, float _health, float _attack)
{
    level = _level;
    health = health*_health;
    current_strenght = flyweight->strenght*_attack;
}

Bat::Bat()
{
    flyweight =  FlyweightFactory::GetBatFl();
    this->health = flyweight->maxHealth;
    this->stamina = flyweight->maxStamina;
    this->speed = 10;
    this->experience = 2;
}

Skeleton::Skeleton()
{
    flyweight =  FlyweightFactory::GetSkeletonFl();
    this->stamina = flyweight->maxStamina;
    this->health = flyweight->maxHealth;
    this->experience = 8;
    this->speed = 3;

}

Ghost::Ghost()
{

    flyweight =  FlyweightFactory::GetGhostFl();
    this->speed = 4;
    this->health = flyweight->maxHealth;
    this->stamina = flyweight->maxStamina;
    this->experience = 6;

}

Shaman::Shaman()
{
    flyweight =  FlyweightFactory::GetShamanFl();
    this->health = flyweight->maxHealth;
    this->stamina = flyweight->maxStamina;
    this->experience = 10;
    this->speed = 10;
}

Golem::Golem()
{

    flyweight =  FlyweightFactory::GetGolemFl();

    this->stamina = flyweight->maxStamina;
    this->speed = 1;
    this->health = flyweight->maxHealth;
    this->experience = 5;
}

Skull::Skull()
{

    flyweight =  FlyweightFactory::GetSkullFl();

    this->experience = 5;
    this->speed = 10;
    this->health = flyweight->maxHealth;
    this->stamina = flyweight->maxStamina;
}

Flyweight *FlyweightFactory::GetGhostFl(){
    if(!storage.contains(Monsters::ghost)){
        Flyweight* create = new Flyweight;
        vector<Items> _loot;
        _loot.push_back(Items::ectoplasm);
        create->loot = _loot;
        create->type = Monsters::ghost;
        create->maxHealth = 40;
        create->maxStamina = 20;
        create->drop_on_damage = false;
        create->strenght = 5;
        create->attack_radius = 5;
        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Ghost.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;
        storage[Monsters::ghost] = create;
    }
    return storage[Monsters::ghost];
}

Flyweight *FlyweightFactory::GetBatFl(){
    if(!storage.contains(Monsters::bat)){
        Flyweight* create = new Flyweight;
        vector<Items> _loot;
        _loot.push_back(Items::bat_wings);
        create->loot = _loot;
        create->type = Monsters::bat;
        create->maxHealth = 15;
        create->maxStamina = 20;
        create->strenght = 3;
        create->drop_on_damage = false;
        create->attack_radius = 1;

        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Bat.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;
        storage[Monsters::bat] = create;
    }
    return storage[Monsters::bat];
}

Flyweight *FlyweightFactory::GetSkeletonFl(){
    if(!storage.contains(Monsters::skeleton)){
        Flyweight* create = new Flyweight;
        vector<Items> _loot;
        _loot.push_back(Items::bone);
        _loot.push_back(Items::cursed_dust);
        create->loot = _loot;
        create->type = Monsters::skeleton;
        create->maxHealth = 50;
        create->maxStamina = 40;
        create->strenght = 10;
        create->drop_on_damage = true;
        create->attack_radius = 2;
        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Skeleton.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;
        storage[Monsters::skeleton] = create;
    }
    return storage[Monsters::skeleton];
}

Flyweight *FlyweightFactory::GetShamanFl(){
    if(!storage.contains(Monsters::shaman)){
        Flyweight* create = new Flyweight;

        vector<Items> _loot;
        _loot.push_back(Items::gunpowder);
        create->loot = _loot;
        create->type = Monsters::shaman;
        create->maxHealth = 20;
        create->maxStamina = 50;
        create->strenght = 3;
        create->drop_on_damage = false;
        create->attack_radius = 15;

        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Shaman.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;

        storage[Monsters::shaman] = create;
    }
    return storage[Monsters::shaman];
}

Flyweight *FlyweightFactory::GetGolemFl(){
    if(!storage.contains(Monsters::golem)){
        Flyweight* create = new Flyweight;
        vector<Items> _loot;
        _loot.push_back(Items::stone);
        create->loot = _loot;
        create->type = Monsters::golem;
        create->maxHealth = 60;
        create->maxStamina = 20;
        create->strenght = 10;
        create->drop_on_damage = false;
        create->attack_radius = 4;
        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Golem.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;
        storage[Monsters::golem] = create;
    }
    return storage[Monsters::golem];
}

Flyweight *FlyweightFactory::GetSkullFl(){
    if(!storage.contains(Monsters::skull)){
        Flyweight* create = new Flyweight;

        vector<Items> _loot;
        _loot.push_back(Items::cursed_dust);
        create->loot = _loot;
        create->type = Monsters::skull;
        create->maxHealth = 20;
        create->maxStamina = 100;
        create->strenght = 4;
        create->drop_on_damage = false;
        create->attack_radius = 1;

        QPixmap pix("C:\\Users\\Nout\\Documents\\Qt_Projects\\MAPZ_6-7\\Monsters\\Skull.png");
        QPixmap* icon = new QPixmap;
        *icon = pix.scaled(30,30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        create->texure = icon;
        storage[Monsters::skull] = create;
    }
    return storage[Monsters::skull];
}
