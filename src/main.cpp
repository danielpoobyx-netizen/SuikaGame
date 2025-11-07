#include "raylib.h"
#include "Fruit.hpp"
#include "Player.hpp"
#include "Container.hpp"
#include "FruitType.hpp"
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
    //player hand
    int rnum = GetRandomValue(0,4);
    Fruit fruit(fruitTypes[rnum]);

    //gameloop
    while(!WindowShouldClose())
            { 
                BeginDrawing();
                ClearBackground(BLUE); //clear backhroudd
                container.Draw(); //draw container
                
                
                
                fruit.Draw();
                fruit.ReleaseChecker();
                fruit.Release();
                fruit.Gravity();
                fruit.Move();
                fruit.Limit(container.container_position, container.container_size);
                
                
                //checks to see if the fruit is grounded if it is then create a new fruit
                if (fruit.grounded) 
                    {
                        int rnum_new = GetRandomValue(0,4);
                        fruit.Replace(fruitTypes[rnum_new]);
                    }

                /*tier1.Move();
                tier1.ReleaseChecker();
                tier1.Release();
                tier1.Gravity();
                tier1.Draw(); //draw tier1
                tier1.Limit(container.container_position, container.container_size);
                */
                EndDrawing();
            }
        
    CloseWindow();
    };  