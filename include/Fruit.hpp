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

            //fruit// gravity
            Vector2 conSize;
            float gravity = 400.0f;
            float fruit_velocity = 0.0f;// the ball starts with no velovity
            bool IsFalling = false; // false: staionary, try: falling

            //physics// normal the fruit is not grounded
            bool IsHeld = true;
            bool grounded = false;
            

            Fruit(Vector2 position, int size, Color color, int speed);
            void Draw();
            void Move();
            //void StayInside(const Container &container);
            void Limit(Vector2 container_position, Vector2 conSize);
            //physics
            void ReleaseChecker();
            void Gravity();
            void Release();
            void Held();
    };