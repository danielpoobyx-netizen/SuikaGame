#include "raylib.h"
#include "Fruit.hpp"
#include "Container.hpp"
#include <iostream>

//this automatically loads but it needs to be specified when making a object
Fruit::Fruit(Vector2 position, int size, Color color, int speed)
    {
        fruit_pos = position;
        fruit_size_r = size;
        fruit_color = color;
        fruit_speed = speed;
    };


void Fruit::Draw()
    {
        //remember you are using vector2 so use a vector2.Ie the vector version of DrawCircleV  
        DrawCircleV(fruit_pos, fruit_size_r, fruit_color);
    };

void Fruit::Move()
    {
        if (IsKeyDown(KEY_LEFT)){fruit_pos.x -= fruit_speed;};
        if (IsKeyDown(KEY_RIGHT)){fruit_pos.x += fruit_speed;};
    }

void Fruit::StayInside(const Container &container)
    {
        container.Clamp(fruit_pos, fruit_size_r);
    }

void Fruit::Gravity()
    {
        
        if (IsKeyPressed(KEY_SPACE)) {IsFalling = true;}; //if space bar has been pressed (one instance) then we make IsFalling true

        if (IsFalling){ //if this is true then proceed with this line of code
            fruit_velocity += gravity * GetFrameTime(); //gravity acceleration
            fruit_pos.y += fruit_velocity * GetFrameTime();
        }
        //if (fruit_pos.y <= Container )
    }