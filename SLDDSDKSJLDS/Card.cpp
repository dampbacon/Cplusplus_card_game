#include "Card.hpp"


const char* Card::cardBack = "PixelCard_Assets/Cards/Card_Back_Blue_New.png";


Card::Card(SUIT suit, int value, const char* texture, int x,int y, bool InPlay) {
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
	
	//draggable
	if (InPlay) {
		active = true;
	}
	else {
		active = false;
	}

	objTexture = TextureManager::LoadTexture(texture);
	cardBackTexture = TextureManager::LoadTexture(Card::cardBack);

	xpos = x;
	ypos = y;

	srcRect.h = 96;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;
	

	//destRect can act as FULL card hitbox
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	destRect.x = xpos;
	destRect.y = ypos;

	cardTopRect.h = cardTop*2;
	cardTopRect.w = destRect.w;
	cardTopRect.x = xpos;
	cardTopRect.y = ypos;
	//14
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
	//xpos++;
	//ypos++;

	destRect.x = xpos;
	destRect.y = ypos;

	cardTopRect.x = xpos;
	cardTopRect.y = ypos;

	if (xpos == 300) {
		flip();
	}
	if (xpos == 500) {
		flip();
	}
}

void Card::Render() {
	if (faceUp) {
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	}
	else {
		SDL_RenderCopy(Game::renderer, cardBackTexture, &srcRect, &destRect);

	}
}

void Card::setPos(int x, int y) {
	xpos = x;
	ypos = y;
	destRect.x = x;
	destRect.y = y;
}

void Card::toggleDrag() {
	active = !active;
}

