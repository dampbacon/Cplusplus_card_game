#pragma once

class Card
{
public:
	Card();
	~Card();
	void flip();
	int getVal();
	int getSuit();
	int getColor();

private:
	bool faceUp;
	SUIT suit;
	SUIT_COLOR color;
};

enum SUIT {
	HEARTS,DIAMONDS,CLUBS,SPADES
};

enum SUIT_COLOR {
	RED,BLACK
};