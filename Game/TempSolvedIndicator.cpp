#include "TempSolvedIndicator.hpp"
TempSolvedIndicator::TempSolvedIndicator(const char* texture, int x, int y, bool visable) {
	objTexture = TextureManager::LoadTexture(texture);
	visableABC = visable;


	xpos = x;
	ypos = y;
	//312, 100

	srcRect.h = 100;
	srcRect.w = 312;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	destRect.x = xpos;
	destRect.y = ypos;

}

TempSolvedIndicator::~TempSolvedIndicator()
{
}

void TempSolvedIndicator::Show() {
	visableABC = true;
}
void TempSolvedIndicator::Hide() {
	visableABC = false;
}

void TempSolvedIndicator::Render() {
	if (visableABC) {
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	}
}

void TempSolvedIndicator::Update()
{
}

