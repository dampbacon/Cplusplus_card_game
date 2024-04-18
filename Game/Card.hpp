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
	Card(SUIT suit, int value, const char* texture,  int x, int y, bool InPlay);
	~Card();
	void flip();
	int getVal();
	SUIT getSuit();
	SUIT_COLOR getColor();

	//only called in Stack class in the update function
	bool ActiveCollision;
	bool Collide(SDL_Point* point, bool topCard, bool simpleCollide);

	void Render();
	void Update();

	void setPos(int x, int y, bool setHome);

	int getXpos();
	int getYpos();

	void toggleDrag();
	bool isDraggable();
	void setDraggable(bool canBeDragged);

	//location for card to snap back to upon release on an invalid pile
	int homeXpos;
	int homeYpos;

	int getCardTopRectHeight();
	void setCardTopRectHeight(int newH);

private:
	int xpos;
	int ypos;

	


	const int cardTop = 16;
	static const char* cardBack;
	SDL_Texture* cardBackTexture;

	int val;

	bool faceUp;
	bool draggable;

	SUIT Csuit;
	SUIT_COLOR color;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect, cardTopRect;
};



//card will have a top stat if top card has full hitbox else it just has the stack card offset i.e the top of the card thats visable as the hitbox