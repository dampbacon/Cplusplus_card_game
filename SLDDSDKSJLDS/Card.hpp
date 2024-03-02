#include "Game.hpp"
#pragma once

enum SUIT {
	HEARTS, DIAMONDS, CLUBS, SPADES
};

enum SUIT_COLOR {
	RED, BLACK
};

class Card
{
public:
	Card(SUIT suit, int value, const char* texture, SDL_Renderer* ren,  int x, int y);
	~Card();
	void flip();
	int getVal();
	SUIT getSuit();
	SUIT_COLOR getColor();


	void Render();
	void Update();

private:
	int xpos;
	int ypos;


	int val;
	bool faceUp;
	SUIT Csuit;
	SUIT_COLOR color;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};


//card will have a top stat if top card has full hitbox else it just has the stack card offset i.e the top of the card thats visable as the hitbox