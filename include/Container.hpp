#pragma once
#include "raylib.h"
#include "Fruit.hpp"
#include "Player.hpp"

class Container
{
    public:
        
        //for the rectangle// it can be whatever because this is for the class i guess
        Vector2 container_position;
        Vector2 container_size;
        Color container_color;
        int offset = 70;

        Container();
        void Draw();
        void Center(int window_width, int window_height);   
        
        //its saying for clamp to work I need a vector2 the original one and a float
        //void Clamp(Vector2 &point, float radius) const;
};