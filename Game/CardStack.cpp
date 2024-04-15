#include "Stack.hpp"
#define DEBUG
using namespace cardStacks;
PlayStack::PlayStack(int ID, FunctionPtr ptr) : Stack() {
	Stack_ID = ID;
	stackHitBox->x = 140 * Stack_ID + 10;
	stackHitBox->y = 288;
	type = PLAYSTACK;
	if (ptr != nullptr) {
		stackRules = ptr;
	}
	else {
		stackRules = defaultFunction;
	}
}

PlayStack::~PlayStack() {
}

int PlayStack::getStackID() {
	return Stack_ID;
}

StackType PlayStack::getType() {
	return type;
}



 void PlayStack::addToStack(Card* card) {

	CardStack.push_back(card);
	card->setPos((140 * Stack_ID + 10), stackHitBox->y+(CardStack.size()-1) * 32, true);
}

void PlayStack::addToStack(const std::vector<Card*>& cards) {
	for (Card* card : cards) {
		CardStack.push_back(card);
		card->setPos((140 * Stack_ID + 10), stackHitBox->y+(CardStack.size() - 1) * 32, true);
	}
}



void PlayStack::transferStack(const std::vector<Card*>& cards, Stack* destStack) {
	if ((destStack != this && (destStack)->stackRules(cards,destStack))) {
		std::cout << stackRules(cards, destStack) << "]]]]]]]]]]]]]]]]]]]]\n";
		destStack->addToStack(cards);

		// Remove transferred cards from current stack
		for (const auto& card : cards) {
			auto it = std::find(CardStack.begin(), CardStack.end(), card);
			if (it != CardStack.end()) {
				CardStack.erase(it);
			}
		}
	}
}
void PlayStack::transferStack(Card* card, Stack* destStack) {
	if (destStack != this) {
		auto it = std::find(CardStack.begin(), CardStack.end(), card);
		if (it != CardStack.end()) {
			CardStack.erase(it);
		}
		destStack->addToStack(card);

	}
}

bool PlayStack::Collide(SDL_Point* mouse, collisionType type) {
	bool collisionDetected = false;
	bool stupidTemp = false;
	if (type == BasicCollision) {
		stupidTemp = true;
	}

	if (!CardStack.empty()) {

		auto start = std::find_if(CardStack.begin(), CardStack.end(), [&](const auto& card) {
			bool collided = card->Collide(mouse, card == CardStack.back(), stupidTemp);
			if (collided)
				collisionDetected = true;
			return collided;
			});

		switch (type) {
		case MouseStackEnable:
		{
			mouseCardStack.clear(); // Clear the existing subStack
			if (start != CardStack.end()) {
				mouseCardStack.assign(start, CardStack.end());
				// Now subStack contains all cards in CardStack after the collided card, including the collided card itself
			}
			break;
		}
		case MouseButtonRelease:
		{
			//fancy logic for dropping stacks of cards onto other stacks
			break;
		}
		default:
			break;
		}
	}
	else {
		collisionDetected = SDL_PointInRect(mouse, stackHitBox);
	}


	return collisionDetected;
}

void PlayStack::ReleaseMouse() {
	//potential area for a "Lock" when animating
	for (auto const& i : CardStack) {
		i->ActiveCollision = false;
		i->setPos(i->homeXpos, i->homeYpos, false);
	}
	mouseCardStack.clear(); // Clear the existing subStack
};
