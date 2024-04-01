#pragma once
#include <vector>
#include "Card.hpp"
#include "Game.hpp"
enum collisionType {
	MouseStackEnable,
	MouseButtonRelease,
	BasicCollision
};

enum CardStackType {
	SameSuitAsc,
	AlternatingColorDsc
};


class Stack
{
public:
	//Stack(int ID);
	Stack(int x, int y);
	Stack();
	~Stack();

	std::vector <Card*> CardStack;
	std::vector <Card*> mouseCardStack;

	//ADD STACK HITBOX, STACK TEXTURE AND STACK COLLIDE
	//THIS IS NEEDED TO ITERACT WITH EMPTY STACKS
	SDL_Rect* stackHitBox;
	void Render();
	void RenderMouseStack();
	void update();
	void ReleaseMouse();

	virtual void addToStack(Card* card) =0;
	virtual void addToStack(const std::vector<Card*>& cards)=0;
	virtual void transferStack(const std::vector<Card*>& cards, Stack* destStack)=0;
	virtual void transferStack(Card* card, Stack* destStack)=0;
	virtual bool Collide(SDL_Point* mouse, collisionType type)=0;
};

class CardStack1 : public Stack { // Modified this line
public:
	CardStack1(int ID);
	~CardStack1();
	int getStackID();

	//used to flip top card if mousestack empty and topcard is not flipped
	void revealTopCard();
	//game logic
	void canBeAdded(std::vector<Card*>& cards);


	void addToStack(Card* card) override;
	void addToStack(const std::vector<Card*>& cards) override;
	void transferStack(const std::vector<Card*>& cards, Stack* destStack) override;
	void transferStack(Card* card, Stack* destStack) override;
	bool Collide(SDL_Point* mouse, collisionType type) override;
private:
	int Stack_ID;
};



class DrawPile : public Stack { // Modified this line
public:
	DrawPile(int x, int y);
	~DrawPile();
    void shuffleCards();
	void takeAllCards();
	void deal();
	void renderDealPile();
	void updateDealPile();

	void ReleaseMouse();

	//only render/show top 3 cards
	std::vector <Card*> dealStack;



	void addToStack(Card* card) override;
	void addToStack(const std::vector<Card*>& cards) override;
	void transferStack(const std::vector<Card*>& cards, Stack* destStack) override;
	void transferStack(Card* card, Stack* destStack) override;
	bool Collide(SDL_Point* mouse, collisionType type) override;
private:
};


