#pragma once
#include <string>
#include "FruitType.hpp"
#include "raylib.h"

using namespace std;
class Container;

/*struct FruitType {
    string name;
    Vector2 position;
    int size;
    Color color;
    float speed;
};*/

//to make the fruit we need its _position_size_color
class Fruit
    {
        public:
            Vector2 fruit_pos;
            int fruit_size_r;
            Color fruit_color;
            float fruit_speed;
            
            //Spawn_Positions
            Vector2 spawn_point;

            //fruit// gravity
            Vector2 conSize;
            float gravity = 400.0f;
            float fruit_velocity = 0.0f;// the ball starts with no velovity
            bool IsFalling = false; // false: staionary, try: falling

            //physics// normal the fruit is not grounded
            bool IsHeld = true;
            bool grounded = false;
            
            //my constructor
            Fruit(FruitType type);
            void Draw();
            void Move();
            //void StayInside(const Container &container);
            void Limit(Vector2 container_position, Vector2 conSize);
            //physics
            void ReleaseChecker();
            void Gravity();
            void Release();
            void Held();
            void Replace(FruitType type);
    };