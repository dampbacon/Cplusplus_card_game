#include "Stack.hpp"
#define DEBUG

CardStack1::CardStack1(int ID) : Stack() {
	Stack_ID = ID;
	stackHitBox->x = 140 * Stack_ID + 10;
	stackHitBox->y = 32;
}

CardStack1::~CardStack1() {
}

int CardStack1::getStackID() {
	return Stack_ID;
}



 void CardStack1::addToStack(Card* card) {
	/*if (!CardStack.empty()) {
		CardStack.back();
	}*/
	CardStack.push_back(card);
	card->setPos((140 * Stack_ID + 10), CardStack.size() * 32, true);
}

void CardStack1::addToStack(const std::vector<Card*>& cards) {
	for (Card* card : cards) {
		CardStack.push_back(card);
		card->setPos((140 * Stack_ID + 10), CardStack.size() * 32, true);
	}
}



void CardStack1::transferStack(const std::vector<Card*>& cards, Stack* destStack) {
	if (destStack != this) {
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
void CardStack1::transferStack(Card* card, Stack* destStack) {
	if (destStack != this) {
		auto it = std::find(CardStack.begin(), CardStack.end(), card);
		if (it != CardStack.end()) {
			CardStack.erase(it);
		}
		destStack->addToStack(card);

	}
}

bool CardStack1::Collide(SDL_Point* mouse, collisionType type) {
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
