#include "raylib.h"
#include "Fruit.hpp"
#include "Player.hpp"
#include "Container.hpp"
#include <iostream>


using namespace std;
//Initwindow values
float window_size_x = 1580;
float window_size_y = 900;

int main()
{
    InitWindow(window_size_x, window_size_y, "Pills for joy");
    
    //container maker and centerer?
    Container container;
    container.Center(window_size_x, window_size_y);

    //object tier1// starting position is outside the container
    Fruit tier1 ({10,90},40, RED, 1);

    //gameloop
    while(!WindowShouldClose())
            { 
                BeginDrawing();
                ClearBackground(BLUE); //clear backhroudd
                container.Draw(); //draw container
                
                tier1.Move();
                tier1.Gravity();
                tier1.Draw(); //draw tier1
                
                //Limit.x
                tier1.StayInside(container);
                
                EndDrawing();
            }
        
    CloseWindow();
    };  