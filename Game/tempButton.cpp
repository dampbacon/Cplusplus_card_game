#include "tempButton.hpp"

tempButton::tempButton()
{
	buttonHitBox = new SDL_Rect();
	buttonHitBox->w = 100;
	buttonHitBox->h = 50;
	buttonHitBox->x = 400;
	buttonHitBox->y = 400;
}

tempButton::tempButton(int x, int y)
{
	//buttonHitBox;
	buttonHitBox = new SDL_Rect();
	buttonHitBox->w = 100;
	buttonHitBox->h = 50;
	buttonHitBox->x = y;
	buttonHitBox->y = x;

}

tempButton::~tempButton()
{
}

void tempButton::render()
{
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255); // Red color
	SDL_RenderFillRect(Game::renderer, buttonHitBox);
	SDL_SetRenderDrawColor(Game::renderer, 21, 88, 67, 255);// green color
}

bool tempButton::collide(SDL_Point* mouse)
{
	return SDL_PointInRect(mouse,buttonHitBox);
}
