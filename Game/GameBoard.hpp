#pragma once
#include <vector>
#include "Card.hpp"
#include "Stack.hpp"
#include "Game.hpp"
#include "tempButton.hpp"
#include "TempSolvedIndicator.hpp"

#include <SDL.h>
// GameBoard will handle all the game card Stack
using namespace cardStacks;
namespace gameObjects {
	class GameBoard
	{
	public:
		GameBoard();
		~GameBoard();
		void handleEvents(SDL_Event event);
		void update();
		void render();
		bool checkWinState();

		bool PAINTMODE = false;

		//gamefunctions

	private:
		bool ANIMATION_LOCK;
		bool solved = false;
		
		std::vector <Stack*> cardStacks = {};


		std::vector <Stack*> playStacks = {};
		std::vector <Stack*> finalStacks = {};

		std::vector <Card*> Cards;
		DrawPile* drawPile;

		//Stack* pointerCollideStack;
		Stack* s0;
		Stack* s1;
		Stack* s2;
		Stack* s3;
		Stack* s4;
		Stack* s5;
		Stack* s6;

		Stack* d0;
		Stack* d1;
		Stack* d2;
		Stack* d3;

		tempButton button1;
		tempButton button2;

		TempSolvedIndicator indicator;

		int animationCount=0;
		int solvePassCounter = 0;

		int prevAnimatedStack = 0;
		Card* prevAnimatedCard = nullptr;
	};
}