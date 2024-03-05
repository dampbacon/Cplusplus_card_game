#include "Card.hpp"


const char* Card::cardBack = "PixelCard_Assets/Cards/Card_Back_Blue_New.png";


Card::Card(SUIT suit, int value, const char* texture, int x,int y, bool InPlay) {
	color = {};
	Csuit = {};
	if (suit == DIAMONDS || suit == HEARTS) {
		color = RED;
	}
	else {
		color = BLACK;
	}
	Csuit = suit;
	faceUp = true;
	val = value;
	
	//draggable
	if (InPlay) {
		draggable = true;
	}
	else {
		draggable = false;
	}

	objTexture = TextureManager::LoadTexture(texture);
	cardBackTexture = TextureManager::LoadTexture(Card::cardBack);

	xpos = x;
	ypos = y;

	homeXpos= xpos;
	homeYpos= ypos;

	bool ActiveCollision = false;


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
	if (ActiveCollision) {
		//later make this a bilinear interpolation to make it a smooth motion towards the mouse cursor
		int x, y;
		SDL_GetMouseState(&x, &y);
		xpos = x-Game::deltaX;
		ypos = y-Game::deltaY;
	}


	destRect.x = xpos;
	destRect.y = ypos;

	cardTopRect.x = xpos;
	cardTopRect.y = ypos;
}

void Card::Render() {
	if (faceUp) {
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	}
	else {
		SDL_RenderCopy(Game::renderer, cardBackTexture, &srcRect, &destRect);

	}
}


//a semi regid position setting function
void Card::setPos(int x, int y, bool setHome) {
	xpos = x;
	ypos = y;
	destRect.x = x;
	destRect.y = y;
	if (setHome) {
		homeXpos = xpos;
		homeYpos = ypos;
	}

}

int Card::getXpos() {
	return xpos;
}

int Card::getYpos() {
	return ypos;
}

void Card::toggleDrag() {
	draggable = !draggable;
}

bool Card::Collide(SDL_Point *point, bool topCard, bool simpleCollide){
	if (ActiveCollision) {
		return false;
	}
	if (!topCard) {
		if (SDL_PointInRect(point, &cardTopRect)) {
			std::cout << "collide " << val << std::endl;
			if(!simpleCollide)
				ActiveCollision = true;

			Game::deltaX = point->x - cardTopRect.x;
			Game::deltaY = point->y - cardTopRect.y;

			return(true);
		}
	}
	else {
		if (SDL_PointInRect(point, &destRect)) {
			std::cout << "collide "<< val << std::endl;
			if (!simpleCollide)
				ActiveCollision = true;

			Game::deltaX = point->x - cardTopRect.x;
			Game::deltaY = point->y - cardTopRect.y;

			return(true);
		}
	}

	return false;
}
