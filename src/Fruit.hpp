#pragma once
#include "raylib.h"

class Container;

//to make the fruit we need its _position_size_color
class Fruit
    {
        public:
            Vector2 fruit_pos;
            int fruit_size_r;
            Color fruit_color;
            float fruit_speed;

            //fruit physics
            float gravity = 400.0f;
            float fruit_velocity = 0.0f;// the ball starts with no velovity
            bool IsFalling = false; // false: staionary, try: falling
            

            Fruit(Vector2 position, int size, Color color, int speed);
            void Draw();
            void Move();
            void StayInside(const Container &container);
            void Gravity();
    };