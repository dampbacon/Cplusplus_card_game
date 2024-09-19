#include "Stack.hpp"
#define DEBUG

using namespace cardStacks;

Stack::Stack()
{
	yRenderOffset = 32;
	CardStack = {};
	mouseCardStack = {};
	stackHitBox = new SDL_Rect();
	stackHitBox->x = 0;
	stackHitBox->y = 0;
	stackHitBox->h = 192;
	stackHitBox->w = 128;
}

Stack::Stack(int x, int y)
{
	yRenderOffset = 32;
	CardStack = {};
	mouseCardStack = {};
	stackHitBox = new SDL_Rect();
	stackHitBox->x = x;
	stackHitBox->y = y;
	stackHitBox->h = 192;
	stackHitBox->w = 128;
}


Stack::~Stack() {
}

void Stack::Render() {
	if (defaultRenderMode){
		SDL_SetRenderDrawColor(Game::renderer, 15, 64, 49, 255); // Red color
		SDL_RenderFillRect(Game::renderer, stackHitBox);
		SDL_SetRenderDrawColor(Game::renderer, 21, 88, 67, 255);// green color
	}



	if (!CardStack.empty()) {
		for (auto const& i : CardStack) {
			if (mouseCardStack.empty()) {
				if (defaultRenderMode) {
					i->Render();
				}
				else if (i->victoryFlag) {
					i->Render();
				}
			}
			else if (i == mouseCardStack.front()) {
				break;
			}
			else {
				i->Render();
			}
		}
	}
}
void Stack::RenderMouseStack() {
	if (!mouseCardStack.empty()) {
		for (auto const& i : mouseCardStack) {
			i->Render();
		}
	}
}
void Stack::update() {
	if (!CardStack.empty()) {
		for (auto const& i : CardStack) {
			i->Update();
		}
	}
	if (!mouseCardStack.empty()) {
		for (size_t i = 1; i < mouseCardStack.size(); ++i) {
			mouseCardStack[i]->setPos(mouseCardStack.front()->getXpos(), mouseCardStack.front()->getYpos()+(i * 32), false);
		}
	}
}


