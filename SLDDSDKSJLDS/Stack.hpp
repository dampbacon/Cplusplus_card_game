#pragma once
#include <vector>
#include "Card.hpp"
/*
add to stack function that sets card postiions.

Stack has a list/array of pointers that holds cards, each card postion is determined by position in list (y offset), x offset is const.

function to remove a group of cards and move to another stack, click drag.

value for top of stack to calculate a hitbox



*/
class Stack
{
public:
	Stack(int ID);
	~Stack();

	std::vector <Card*> CardStack;

	int getStackID();
	
	void addToStack(Card* card);
	void transferStack(Card* card, Stack* destStack);

private:
	int Stack_ID;

};
