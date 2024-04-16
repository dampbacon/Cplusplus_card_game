#pragma once
#include "Game.hpp"
class tempButton
{
public:
	tempButton();
	tempButton(int x, int y);
	~tempButton();
	void render();
	bool collide(SDL_Point* mouse);
	SDL_Rect* buttonHitBox;
private:

};

