#include "Game.hpp"
#include "TextureManager.hpp"
#pragma once
class TempSolvedIndicator
{
public:
	TempSolvedIndicator(const char* texture="solved.png", int x = 0, int y = 0, bool visable = false);
	~TempSolvedIndicator();
	void Render();
	void Update();
	void Hide();
	void Show();

private:
	bool visableABC;
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
