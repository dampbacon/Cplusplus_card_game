
#include "Stack.hpp"

DrawPile::DrawPile(int x, int y) : Stack() {
	stackHitBox->x = x;
	stackHitBox->y = y;
}

DrawPile::~DrawPile() {
}






//TBD
void DrawPile::addToStack(Card* card) {

	CardStack.push_back(card);
	card->setPos(stackHitBox->x, stackHitBox->y + (CardStack.size()-1) * 6, true);
}

void DrawPile::addToStack(const std::vector<Card*>& cards) {

	if (!this->CardStack.empty()) {
		for (auto i : CardStack) {
			i->setDraggable(false);
		}
	}

	for (Card* card : cards) {
		card->setDraggable(false);
		CardStack.push_back(card);
		card->setPos(stackHitBox->x, stackHitBox->y + (CardStack.size() - 1) * 6, true);
	}
	CardStack.back()->setDraggable(true);
}


void DrawPile::transferStack(const std::vector<Card*>& cards, Stack* destStack) {
	if (destStack != this) {
		destStack->addToStack(cards);
		for (const auto& card : cards) {
			auto it = std::find(CardStack.begin(), CardStack.end(), card);
			if (it != CardStack.end()) {
				CardStack.erase(it);
			}
		}

		if (!this->CardStack.empty()) {
			CardStack.back()->toggleDrag();
		}
	}
}

void DrawPile::transferStack(Card* card, Stack* destStack) {
	if (destStack != this) {
		auto it = std::find(CardStack.begin(), CardStack.end(), card);
		if (it != CardStack.end()) {
			CardStack.erase(it);
		}
		destStack->addToStack(card);
		if (!this->CardStack.empty()) {
			CardStack.back()->toggleDrag();
		}
	}
}

bool DrawPile::Collide(SDL_Point* mouse, collisionType type) {
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
