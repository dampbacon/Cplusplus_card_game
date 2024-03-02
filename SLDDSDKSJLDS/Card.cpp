#include "Card.hpp"
#include "TextureManager.hpp"
Card::Card(SUIT suit, int value, const char* texture, SDL_Renderer* ren, int x,int y) {
	color = {};
	Csuit = {};
	if (suit == DIAMONDS || suit == HEARTS) {
		color == RED;
	}
	else {
		color == BLACK;
	}
	Csuit = suit;
	faceUp = true;
	val = value;



	renderer = ren;
	objTexture = TextureManager::LoadTexture(texture,renderer);
	xpos = x;
	ypos = y;
}

Card::~Card(){}

int Card::getVal() {
	return val;
}

void Card::flip() {
	faceUp = !faceUp;
}

SUIT Card::getSuit() {
	return Csuit;
}

SUIT_COLOR Card::getColor() {
	return color;
}

void Card::Update() {
	xpos++;
	ypos++;

	srcRect.h = 96;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	destRect.x = xpos;
	destRect.y = ypos;
}

void Card::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
