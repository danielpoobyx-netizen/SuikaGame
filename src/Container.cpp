#include "raylib.h"
#include "Container.hpp"
#include "Fruit.hpp"
#include "Player.hpp"
#include <algorithm>

using namespace std;

Container::Container()
    {
        container_position = {0,0};
        container_size = {550,600};
        container_color = WHITE;
    };

void Container::Draw()
    {
        DrawRectangleV(container_position, container_size, container_color);
    };

void Container::Center(int window_width, int window_height)//this says center the position 
    {
        container_position.x = (window_width - container_size.x) / 2.0f; 
        container_position.y = offset + (window_height - container_size.y) / 2.0f;   
    };

void Container::Clamp(Vector2 &point, float radius) const
    {
        point.x = max(container_position.x + radius, min(point.x, container_position.x + container_size.x - radius));
        //point.y = max(container_position.y + radius, min(point.y, container_position.x + container_size.x -radius)); //dont need this rn
    };