#ifndef ITEMS_H
#define ITEMS_H


enum class Items {red_leaf, orange_leaf, yellow_leaf, green_leaf, blue_leaf, purple_leaf,
                  bat_wings, bone, cursed_dust, ectoplasm, gunpowder, stone,
                 };
enum class Monsters {bat, skeleton, ghost, skull, shaman, golem};
enum class Locations {house, plaines, forest, deep_forest, lake, mountain};
static const char * ItemStrings[] = { "Red leaf", "Orange leaf", "Yellow leaf", "Green leaf", "Blue leaf", "Purple leaf",
                                      "Bat wings", "Bone", "Cursed dust", "Ectoplasm", "Gunpowder", "Stone" };
static const char * MonsterStrings[] = { "Bat", "Skeleton", "Ghost", "Skull", "Shaman", "Golem"};
#endif // ITEMS_Hs
