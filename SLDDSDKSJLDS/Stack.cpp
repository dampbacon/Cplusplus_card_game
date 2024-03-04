#include "Stack.hpp"
#define DEBUG

Stack::Stack(int ID)
{
	Stack_ID = ID;
	CardStack = {};
	mouseCardStack = {};
}

Stack::~Stack()
{
}

int Stack::getStackID() {
	return Stack_ID;
}

void Stack::Render() {

	//make render subsection for drag stack that is called always last so cards dont clip

	if (!CardStack.empty()) {
		for (auto const& i : CardStack) {
			i->Render();
		}
	}
}


//
void Stack::update() {
	if (Game::mouseDown) {
		//add cards to the drag substack make it follow the mouse
	}
	else {
		//check drag subtack if size > 0
		//return cards to main holding stack
		//else just update all cards
	}
}

void Stack::addToStack(Card* card) {
	/*if (!CardStack.empty()) {
		CardStack.back();
	}*/
	CardStack.push_back(card);
	card->setPos((140 * Stack_ID), CardStack.size()*32);
}

void Stack::transferStack(Card* card, Stack* destStack) {

	#ifdef DEBUG
	std::cout << '\n' << "CARD to be moved:" << card << std::endl;

	std::cout << "Before card moved, Stack" << Stack_ID << std::endl;
	for (Card* num : CardStack) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	#endif

	auto it = std::find(CardStack.begin(), CardStack.end(), card);
	if (it != CardStack.end()) {
		CardStack.erase(it);
	}

	#ifdef DEBUG
	std::cout << "After card removed Stack" << Stack_ID << std::endl;
	for (Card* num : CardStack) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	#endif


	destStack->addToStack(card);

	#ifdef DEBUG
	std::cout << "Destination where card was moved Stack"<< destStack->Stack_ID << std::endl;
	for (Card* num : destStack->CardStack) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	#endif
}

void Stack::Collide(SDL_Point* mouse) {
	if (!CardStack.empty()) {
		for (auto const& i : CardStack) {
			if (i == CardStack.back()) {
				i->Collide(mouse,true); //returns bool, assign to some var card collided
			}
			else {
				i->Collide(mouse, false);
			}
		}
	}
}


void Stack::dragSubStack() {

}

void Stack::ReleaseMouse() {
	for (auto const& i : CardStack) {
		i->ActiveCollision=false;
	}
};
