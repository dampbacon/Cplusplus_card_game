#pragma once
#include <vector>
#include "Card.hpp"
#include "Stack.hpp"
#include "Game.hpp"
#include <SDL.h>
// GameBoard will handle all the game card Stack

namespace gameObjects {
	class GameBoard
	{
	public:
		GameBoard();
		~GameBoard();
		void collideMouseDown();
		void collideMouseUp();
		void handleEvents(SDL_Event event);
		void update();
		void render();

	private:
		std::vector <Stack*> CardStacks = {};
		std::vector <Card*> Cards;
		DrawPile* drawPile;

		Stack* pointerCollideStack;
		Stack* s0;
		Stack* s1;
		Stack* s2;
		Stack* s3;
		Stack* s4;
		Stack* s5;
		Stack* s6;
	};
}