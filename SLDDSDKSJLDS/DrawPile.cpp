
#include "Stack.hpp"

DrawPile::DrawPile(int x, int y) : Stack() {
	stackHitBox->x = x;
	stackHitBox->y = y;
	dealStack = std::vector<Card*>();
	type = DEALSTACK;
}

DrawPile::~DrawPile() {
}



StackType DrawPile::getType() {
	return type;
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
		std::cout << "~~~~~~~~~~~~~~~~~~~~AAAAAAAAAAAAAA~~~~~~~~~~~~~~~\n";
		// Remove transferred cards from current stack
		for (const auto& card : cards) {
			auto it = std::find(dealStack.begin(), dealStack.end(), card);
			if (it != dealStack.end()) {
				dealStack.erase(it);
			}
		}
	}
}
void DrawPile::transferStack(Card* card, Stack* destStack) {
	if (destStack != this) {
		auto it = std::find(dealStack.begin(), dealStack.end(), card);
		if (it != dealStack.end()) {
			dealStack.erase(it);
		}
		destStack->addToStack(card);

	}
}





void DrawPile::renderDealPile() {
	if (!dealStack.empty()) {
		for (auto const& i : dealStack) {	
			i->Render();
		}
	}
}

void DrawPile::updateDealPile() {
	if (!dealStack.empty()) {
		for (auto const& i : dealStack) {
			i->Update();
		}
	}
}

void DrawPile::ReleaseMouse() {
	
	for (auto const& i : CardStack) {
		i->ActiveCollision = false;
		i->setPos(i->homeXpos, i->homeYpos, false);
	}
	for (auto const& i : dealStack) {
		i->ActiveCollision = false;
		i->setPos(i->homeXpos, i->homeYpos, false);
	}
	std::cout << "WORKING\n";

	mouseCardStack.clear(); // Clear the existing subStack
}



bool DrawPile::Collide(SDL_Point* mouse, collisionType type) {
	bool collisionDetected = false;
	bool stupidTemp = true;
	if (type==MouseStackEnable) {

		//mainpile
		if (!CardStack.empty()) {
			bool mainPileCollide = CardStack.back()->Collide(mouse, true, stupidTemp);
			if (mainPileCollide) {
				Card* temp = CardStack.back();
				CardStack.pop_back();
				dealStack.push_back(temp);
				temp->setPos(this->stackHitBox->x + 140, this->stackHitBox->y, true);
				dealStack.back()->setDraggable(true);

				if (!CardStack.empty()) {
					CardStack.back()->setDraggable(true);
				}
			}
		}
		//dealt pile
		if (!dealStack.empty()) {
			bool dealPileCollide = dealStack.back()->Collide(mouse, true, false);
			if (dealPileCollide)
			{
				mouseCardStack.push_back(dealStack.back());
				return true;
			}
		}

				//add to mouscardStack


		std::cout << "\n|||||||||||||||||||||||||||||||||||\n";
		std::cout << "Card Stack:\n";
		for (auto i : CardStack) {
			std::cout << i << '\n';
		}
		std::cout << "dealt pile:\n";
		for (auto i : dealStack) {
			std::cout << i << '\n';
		}
		std::cout << "\n|||||||||||||||||||||||||||||||||||\n";

		switch (type) {
		case MouseStackEnable:
		{
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
