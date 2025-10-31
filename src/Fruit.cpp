#include "raylib.h"
#include <vector>
#include "raymath.h"
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
void Fruit::ReleaseChecker()
    {
        if(IsKeyPressed(KEY_SPACE)){IsHeld = false;};
    }

void Fruit::Release(){
    if (!IsHeld)
        {
            IsFalling = true;

        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Fruit::Gravity()
    {
        
        if (IsHeld) return;//returns if the IsHeld is true effectively ignoring the next block of code

        //making sure the player cannot move the ball in the air
        if (IsFalling) {fruit_speed = 0;};//remove the fruit speed maybe?
        
        if (IsFalling){ //if this is true then proceed with this line of code
            fruit_velocity += gravity * GetFrameTime(); //gravity acceleration
            fruit_pos.y += fruit_velocity * GetFrameTime();
        };
        
    }

void Fruit::Limit(Vector2 container_position, Vector2 conSize)
    {
        //Clamping method for the x axis
        fruit_pos.x = Clamp(fruit_pos.x, container_position.x + fruit_size_r, container_position.x + conSize.x - fruit_size_r);

        //Y axis Limiter
        if (fruit_pos.y + fruit_size_r >= container_position.y + conSize.y)
            {
                fruit_pos.y = container_position.y + conSize.y - fruit_size_r;
                //check if the thing is grounded
                grounded = true;
            }
    }
//when groudned i want the fruit to act like a regular ball
