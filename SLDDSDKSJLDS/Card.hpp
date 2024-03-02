#include "Game.hpp"
#include "TextureManager.hpp"
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
	Card(SUIT suit, int value, const char* texture,  int x, int y);
	~Card();
	void flip();
	int getVal();
	SUIT getSuit();
	SUIT_COLOR getColor();


	void Render();
	void Update();

	void setPos(int x, int y);

private:
	int xpos;
	int ypos;
	const int cardTop = 16;
	static const char* cardBack;
	SDL_Texture* cardBackTexture;

	int val;
	bool faceUp;
	SUIT Csuit;
	SUIT_COLOR color;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect, cardTopRect;
};



//card will have a top stat if top card has full hitbox else it just has the stack card offset i.e the top of the card thats visable as the hitbox