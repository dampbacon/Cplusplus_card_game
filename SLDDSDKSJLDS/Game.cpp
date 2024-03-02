
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Card.hpp"
#include "Stack.hpp"
#include <vector>

Stack* testStack;

Card* testCard;
Card* card2;
Card* card3;
Card* card4; 
Card* card5;



std::vector <Card*> Deck(52);


SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

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

	testStack = new Stack(2);

	testCard = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_2Spades.png",100,100);

	card2 = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_3Spades.png", 100, 132);

	card3 = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_4Spades.png", 100, 164);

	card4 = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_5Spades.png", 100, 196);

	card5 = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_6Spades.png", 100, 228);

	testStack->addToStack(card3);
	testStack->addToStack(card4);
	testStack->addToStack(card5);


}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
		default:
			break;
	}
	
}

void Game::update(){
	testCard->Update();
	card2->Update();
	card3->Update();
	card4->Update();
	card5->Update();


}

void Game::render(){
	SDL_RenderClear(renderer);
	testCard->Render();
	card2->Render();
	card3->Render();
	card4->Render();
	card5->Render();


	
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned." << std::endl;
}
