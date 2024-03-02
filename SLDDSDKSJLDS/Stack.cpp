#include "Stack.hpp"


Stack::Stack(int ID)
{
	Stack_ID = ID;
	CardStack = {};
}

Stack::~Stack()
{
}

void Stack::addToStack(Card* card) {

	CardStack.push_back(card);
	card->setPos(20 + (128 * Stack_ID), CardStack.size()*32);
}