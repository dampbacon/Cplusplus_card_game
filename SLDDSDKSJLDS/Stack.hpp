#pragma once
#include <vector>
#include "Card.hpp"
#include "Game.hpp"
enum collisionType {
	MouseStackEnable,
	MouseButtonRelease,
	BasicCollision
};

/*
add to stack function that sets card postiions.

Stack has a list/array of pointers that holds cards, each card postion is determined by position in list (y offset), x offset is const.

function to remove a group of cards and move to another stack, click drag.

value for top of stack to calculate a hitbox



*/

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

	//dragStack on release return to original stack, else if on another card that can be searched for in the 7 stacks transfer to that stack
	void dragSubStack();

private:
	int Stack_ID;

};
