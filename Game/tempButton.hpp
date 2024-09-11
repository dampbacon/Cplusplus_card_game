#pragma once
#include "Game.hpp"
#include "TextureManager.hpp"
class tempButton
{
public:
	tempButton();
	tempButton(int x, int y, const char* texture = "solved.png");
	~tempButton();
	void render();
	bool collide(SDL_Point* mouse);
	SDL_Rect* buttonHitBox,srcRect;
private:
	SDL_Texture* objTexture;

};

