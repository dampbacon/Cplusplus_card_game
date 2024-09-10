
#include "Stack.hpp"
#include <algorithm>
#include <random>
using namespace cardStacks;
DrawPile::DrawPile(int x, int y, FunctionPtr ptr, int yoffsetRen) : Stack() {
	stackHitBox->x = x;
	stackHitBox->y = y;
	dealStack = std::vector<Card*>();
	type = DEALSTACK;
	yRenderOffset = yoffsetRen;
}

DrawPile::~DrawPile() {
}



StackType DrawPile::getType() {
	return type;
}


//TBD
void DrawPile::addToStack(Card* card) {

	CardStack.push_back(card);
	card->setPos(stackHitBox->x, stackHitBox->y + (CardStack.size() - 1) * yRenderOffset, true);
}

void DrawPile::addToStack(const std::vector<Card*>& cards) {

	if (!this->CardStack.empty()) {
		for (auto i : CardStack) {
			i->setDraggable(false);
		}
	}

	int offset = 0;

	for (Card* card : cards) {
		card->setDraggable(false);
		CardStack.push_back(card);
		//card index
		card->setPos(stackHitBox->x, stackHitBox->y + (CardStack.size() - 1) * yRenderOffset, true);
	}
	CardStack.back()->setDraggable(true);
}

void DrawPile::shuffleCards() {
	
	auto rd = std::random_device{};
	auto rng = std::default_random_engine{ rd() };
	std::shuffle(std::begin(CardStack), std::end(CardStack), rng);

	// fix positioning of shuffled cards

	if (!this->CardStack.empty()) {
		for (auto i : CardStack) {
			i->setDraggable(false);
		}
		int increasingYOffset = 0;

		for (Card* card : CardStack) {
			card->setDraggable(false);
			card->setPos(stackHitBox->x, stackHitBox->y + increasingYOffset, true);
			increasingYOffset += yRenderOffset;
		}
		CardStack.back()->setDraggable(true);
	}


}
;

void DrawPile::deal(std::vector<Stack*>& playstacks, std::vector<Stack*>& finalPiles) {
	//do
	takeAllCards(playstacks);
	takeAllCards(finalPiles);

	shuffleCards();

	Stack* destStack = playstacks[1]; 
	Card* card = CardStack.back();
	
	std::vector<int> StartingPileDealAmmounts = { 1, 2, 3, 4, 5, 6, 7 };
	Stack* dealingStack;

	for (int& i : StartingPileDealAmmounts) {
		dealingStack = playstacks[i - 1];

		for (int j = 0; j < i; j++) {
			if (!CardStack.empty()) {
				std::vector<Card*> tempLazyWorkAround = {};

				Card* cardToMove = CardStack.back();  
				cardToMove->setDraggable(true);
				tempLazyWorkAround.push_back(cardToMove);

				dealingStack->addToStack(tempLazyWorkAround);

				auto it = std::find(CardStack.begin(), CardStack.end(), cardToMove);
				if (it != CardStack.end()) {
					CardStack.erase(it);  
				}
			}
		}
	}
	
	CardStack.back()->setDraggable(true);

/*
	for(auto const& i : CardStack) {
		if (destStack != this) {
			auto it = std::find(CardStack.begin(), CardStack.end(), card);
			if (it != CardStack.end()) {
				CardStack.erase(it);
			}
			destStack->addToStack(card);
		}
		if (!CardStack.empty()) {
			card = CardStack.back();
		}
	}
	*/
}


void DrawPile::transferStack(const std::vector<Card*>& cards, Stack* destStack, bool FORCE) {
	if (FORCE || destStack != this && (destStack)->stackRules(cards, destStack)) {
		destStack->addToStack(cards);
		std::cout << "~~~~~~~~~~~~~~~~~~~~AAAAAAAAAAAAAA~~~~~~~~~~~~~~~\n";

		dealStack.erase(std::remove_if(dealStack.begin(), dealStack.end(),
			[&cards](const Card* card) {
				return std::find(cards.begin(), cards.end(), card) != cards.end();
			}), dealStack.end());
		/*for (const auto& card : cards) {
			auto it = std::find(dealStack.begin(), dealStack.end(), card);
			if (it != dealStack.end()) {
				dealStack.erase(it);
			}
		}*/
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

void DrawPile::takeAllCards(std::vector<Stack*>& input) {
	this->returnDealpile();
	for (auto& i : input) {
		for (auto& j : i->CardStack) {
			std::cout << "TEST_" << j << "\n";
			j->setDraggable(false);
		}
		if (i->getType() == PLAYSTACK && !(i->CardStack.empty())) {
			std::vector<Card*> cardsToTransfer;
			cardsToTransfer.reserve(i->CardStack.size());
			for (const auto& card : i->CardStack) {
				cardsToTransfer.push_back(card);
			}

			this->addToStack(cardsToTransfer);
			i->CardStack.clear();
		}
		

		if (i->getType() == PLAYSTACK) {
			for (auto& j : i->CardStack) {

				std::cout << "SHOULD_BE_EMPTY_" << j << "  " << "\n";
			}
		}
	}
	CardStack.back()->setDraggable(true);
}



bool DrawPile::Collide(SDL_Point* mouse, collisionType type) {
	bool collisionDetected = false;
	bool stupidTemp = true;
	bool stupidflag = false;
	/* 
	stupidflag
	
	This is needed so that cards dont immediatly get cycled back into the pile when dealing the last card to the drawpile
	because the code for cycling checks that the deal stack is empty is after the code for putting cards in the drawpile
	what would happen is that upon drawing the last card it would immediatly undo and cycle all the cards

	i can probably move the code block up and remove the stupid flag but really dont want to touch it now
	it works bleh
	*/

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
		//probably redundant
		if (!(CardStack.empty() && SDL_PointInRect(mouse, stackHitBox))) {
			return collisionDetected;
		}
		if (CardStack.empty() && SDL_PointInRect(mouse, stackHitBox) && !stupidflag) {
			if (!dealStack.empty()) {
				dealStack.back()->setDraggable(false);
				this->returnDealpile();
				if (CardStack.size() == 1) {
					CardStack.back()->setDraggable(true);
				}
			}
		}
	}
	else {
		collisionDetected = SDL_PointInRect(mouse, stackHitBox);
	}
	
	return collisionDetected;
}

void DrawPile::returnDealpile() {
	while (!dealStack.empty()) {
		Card* temp = dealStack.back();
		dealStack.pop_back();
		CardStack.push_back(temp);
		temp->setPos(this->stackHitBox->x, this->stackHitBox->y+(CardStack.size() - 1) * yRenderOffset, true);
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