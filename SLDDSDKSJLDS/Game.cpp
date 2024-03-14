
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Card.hpp"
#include "Stack.hpp"
#include <vector>
#include <algorithm>
#include "GameBoard.hpp"

using namespace gameObjects;




GameBoard* gameBoard = nullptr;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

SDL_Point Game::mousePos = SDL_Point(0,0);

bool Game::mouseDown = false;

int Game::deltaX = 0;
int Game::deltaY = 0;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	int flags = { 0 };
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "subsystems initialised..." << std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 21, 88, 67, 255);
			std::cout << "renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	mousePos.x = 0;
	mousePos.y = 0;

	gameBoard = new GameBoard();



}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);


	//move all mouse stuff here
	gameBoard->handleEvents(event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
	
}

//later in deck class handle all the card shit
void Game::update(){

	
	gameBoard->update();

}
// render order matters this is to be handled by stacks
void Game::render(){
	SDL_RenderClear(renderer);
	
	gameBoard->render();

	
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned." << std::endl;
}
