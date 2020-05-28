#include "resourse.h"
string Resourse::getTexure() const
{
    return texure;
}

int Resourse::getAmounts() const
{
    return amounts;
}

Items Resourse::getLoots() const
{
    return loots;
}

Resourse::Resourse()
{
}


RedLeaf::RedLeaf(){
    this->loots = Items::red_leaf;
   this->amounts = 2;
   this->on_harvest = nullptr;
   this->exp = 1;
    this->texure = "RedLeaf.png";
}

YellowLeaf::YellowLeaf(){
    this->loots = Items::yellow_leaf;
    this->amounts = 1;
    this->on_harvest = nullptr;
    this->exp = 2;
    this->texure = "YellowLeaf.png";

}

BlueLeaf::BlueLeaf(){
    this->loots = Items::blue_leaf;
    this->amounts = 3;
    this->on_harvest = nullptr;
    this->exp = 4;
    this->texure = "BlueLeaf.png";

}

GreenLeaf::GreenLeaf()
{
    this->loots = Items::green_leaf;
    this->amounts = 2;
    this->on_harvest = nullptr;
    this->exp = 4;
    this->texure = "GreenLeaf.png";
}

PurpleLeaf::PurpleLeaf()
{
    this->loots = Items::purple_leaf;
    this->amounts = 1;
    this->on_harvest = nullptr;
    this->exp = 4;
    this->texure = "PurpleLeaf.png";
}

OrangeLeaf::OrangeLeaf()
{
    this->loots = Items::orange_leaf;
    this->amounts = 1;
    this->on_harvest = nullptr;
    this->exp = 4;
    this->texure = "OrangeLeaf.png";
}
