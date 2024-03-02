#pragma once
//The mouse button
#include "Game.hpp"
class Mouse
{
public:
    //Initializes internal variables
    Mouse();

    //Sets top left position
    void setPosition(int x, int y);

    //Handles mouse event
    void handleEvent(SDL_Event* e);

    //Shows button sprite
    void render();

private:
    //Top left position
    SDL_Point mPosition;

    //Currently used global sprite

};