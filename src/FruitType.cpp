#include "raylib.h"
#include "FruitType.hpp"

int spawn_point = 200;
FruitType fruitTypes[10] = {
    {"Tier1", {200,200} , 50 , RED,1},
    {"Tier2", {200,200} , 50 , BROWN,1},
    {"Tier3", {200,200} , 50 , BLUE,1},
    {"Tier4", {200,200} , 50 , GREEN,1},
    {"Tier5", {200,200} , 50 , LIGHTGRAY,1},
    {"Tier6", {0,0} , 10, LIME,1},
    {"Tier7", {0,0} , 12, GOLD,1},
    {"Tier8", {0,0} , 14, ORANGE,1},
    {"Tier9", {0,0} , 15, BEIGE,1},
    {"Tier10", {0,0} , 16, BROWN,1},
};


