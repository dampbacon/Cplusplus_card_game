#include "tempButton.hpp"

tempButton::tempButton()
{	
	objTexture = TextureManager::LoadTexture("solved.png");
	buttonHitBox = new SDL_Rect();
	

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 311;
	srcRect.h = 100;

	buttonHitBox->w = srcRect.w/2;
	buttonHitBox->h = srcRect.h/2;
	buttonHitBox->x = 400;
	buttonHitBox->y = 400;
}

tempButton::tempButton(int x, int y, const char* texture)
{
	objTexture = TextureManager::LoadTexture(texture);
	//buttonHitBox;
	buttonHitBox = new SDL_Rect();


	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 311;
	srcRect.h = 100;
	buttonHitBox->w = srcRect.w / 3;
	buttonHitBox->h = srcRect.h / 3;
	buttonHitBox->x = y;
	buttonHitBox->y = x;

}

tempButton::~tempButton()
{
}

void tempButton::render()
{
	/*
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255); // Red color
	SDL_RenderFillRect(Game::renderer, buttonHitBox);
	SDL_SetRenderDrawColor(Game::renderer, 21, 88, 67, 255);// green color
	*/
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, buttonHitBox);

}

bool tempButton::collide(SDL_Point* mouse)
{
	return SDL_PointInRect(mouse,buttonHitBox);
}
