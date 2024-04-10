﻿
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
	card->setPos(stackHitBox->x, stackHitBox->y, true);
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
		card->setPos(stackHitBox->x, stackHitBox->y, true);
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
	bool stupidflag = false;

	
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
				else {
					stupidflag = true;
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
		if (!(CardStack.empty() && SDL_PointInRect(mouse, stackHitBox))) {
			return collisionDetected;
		}
	}
	else {
		collisionDetected = SDL_PointInRect(mouse, stackHitBox);
	}
	//debug code


	if (type == MouseStackEnable && CardStack.empty() && SDL_PointInRect(mouse, stackHitBox) && !stupidflag) {
		if (!dealStack.empty()) {
			dealStack.back()->setDraggable(false);
			this->returnDealpile();
		}
	}

	return collisionDetected;
}

void DrawPile::returnDealpile() {
	while (!dealStack.empty()) {
		Card* temp = dealStack.back();
		dealStack.pop_back();
		CardStack.push_back(temp);
		temp->setPos(this->stackHitBox->x, this->stackHitBox->y, true);
	}
}
//useful debug collision codeblock
/*
	std::cout << "type :";
	std::string k = "";
	switch (type)
	{
	case MouseButtonRelease: k = "MouseButtonRelease";
		break;
	case MouseStackEnable:   k = "MouseStackEnable";
		break;
	case BasicCollision: k = "BasicCollision";
		break;
	}
	std::cout << k << "\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
*/