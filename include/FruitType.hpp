#pragma once
#include "raylib.h"
#include <string>
using namespace std;

struct FruitType {
    string name;
    Vector2 spawnpoint;
    int size;
    Color color;
    float speed;
};

extern FruitType fruitTypes[10];

