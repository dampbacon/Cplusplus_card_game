#include "Card.hpp"
#include <random>
#include <ctime>



const char* Card::cardBack = "PixelCard_Assets/Cards/Card_Back_Blue_New.png";


Card::Card(SUIT suit, int value, const char* texture, int x,int y, bool InPlay) {
	ActiveCollision = false;
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


	generatePathingVars();
	//deltaX = 0;
	//deltaY = 0;

	homeXpos= xpos;
	homeYpos= ypos;



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

Card::~Card(){
	// Free textures
	SDL_DestroyTexture(objTexture);
	SDL_DestroyTexture(cardBackTexture);
}

int Card::getVal() {
	return val;
}

void Card::flip() {
	faceUp = !faceUp;
}

void Card::setFaceDown() {
	faceUp = false;
}

void Card::setFaceUp() {
	faceUp = true;
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



	if (victoryFlag) {

		if ((int)std::round(deltaX) == 0) {
			deltaX = 3;
		}
		xpos += (int)std::round(deltaX);
		//std::cout << xpos<<" = XPOS\n";

		ypos += (int)std::round(deltaY);


		//currently hardcoded later add functions to dynamically get height and width
		int TEMPwindowwidth = 1024;
		int TEMPwindowheight = 900;

		if (xpos<(-destRect.w / 2) || xpos >(TEMPwindowwidth + destRect.w / 2)) {
			victoryFlag = false;
		}

		if (ypos > TEMPwindowheight - destRect.h / 2) {
			ypos = TEMPwindowheight - destRect.h / 2;
			deltaY = -deltaY * 0.85;
		}
		deltaY += .98;

		// needed so clicking doesnt screw up animation
		// will need to go back and do something to 
		//homeXpos = xpos;
		//homeYpos = ypos;

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

int Card::getCardTopRectHeight() {
	return this->cardTopRect.h;
}

void Card::setCardTopRectHeight(int h) {
	this->cardTopRect.h=h;
}

void Card::generatePathingVars()
{
	std::mt19937 rng(std::time(0));
	std::uniform_real_distribution<float> distX(-8, 8);
	std::uniform_real_distribution<float> distY(-16, 0);


	deltaX = distX(rng); //random number [-6,6]
	deltaY = distY(rng); //random number [-16,0]

}

void Card::toggleDrag() {
	draggable = !draggable;
}
bool Card::isDraggable() {
	return draggable;
}
void Card::setDraggable(bool canBeDragged) {
	draggable = canBeDragged;
}



bool Card::Collide(SDL_Point *point, bool topCard, bool simpleCollide){
	//Lockcheck
	if (draggable) {
		if (ActiveCollision) {
			return false;
		}
		if (!topCard) {
			if (SDL_PointInRect(point, &cardTopRect)) {
				std::cout << "collide " << val << std::endl;
				if (!simpleCollide)
					ActiveCollision = true;

				Game::deltaX = point->x - cardTopRect.x;
				Game::deltaY = point->y - cardTopRect.y;

				return(true);
			}
		}
		else {
			if (SDL_PointInRect(point, &destRect)) {
				std::cout << "collide " << val << std::endl;
				if (!simpleCollide)
					ActiveCollision = true;

				Game::deltaX = point->x - cardTopRect.x;
				Game::deltaY = point->y - cardTopRect.y;

				return(true);
			}
		}
	}

	return false;
}
