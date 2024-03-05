#pragma once
#include <vector>
#include "Card.hpp"
#include "Game.hpp"
enum collisionType {
	MouseStackEnable,
	MouseButtonRelease,
	BasicCollision
};


enum StackType {
	BUILD_STACKS,
	FINAL_STACKS,
	DRAW_STACK
};


class Stack
{
public:
	Stack(int ID);
	~Stack();

	std::vector <Card*> CardStack;
	std::vector <Card*> mouseCardStack;

	//ADD STACK HITBOX, STACK TEXTURE AND STACK COLLIDE
	//THIS IS NEEDED TO ITERACT WITH EMPTY STACKS
	SDL_Rect* stackHitBox;


	int getStackID();
	
	void addToStack(Card* card);
	void addToStack(const std::vector<Card*>& cards);

	void transferStack(const std::vector<Card*>& cards, Stack* destStack);

	void transferStack(Card* card, Stack* destStack);
	void Render();
	void RenderMouseStack();
	void update();

	bool Collide(SDL_Point* mouse, collisionType type);

	void ReleaseMouse();

private:
	int Stack_ID;

};
