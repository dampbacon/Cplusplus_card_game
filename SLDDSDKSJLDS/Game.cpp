
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Card.hpp"
#include "Stack.hpp"
#include <vector>
#include <algorithm>


Stack* testStack = nullptr;
Stack* testStack2 = nullptr;


Stack* collideStack = nullptr;


Card* card0 = nullptr;
Card* card1 = nullptr;
Card* card2 = nullptr;
Card* card3 = nullptr;
Card* card4 = nullptr;
Card* card5 = nullptr;




std::vector <Card*> Deck(52);
std::vector <Stack*> CardStacks ={};

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

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

	testStack = new Stack(2);
	testStack2 = new Stack(3);

	CardStacks.push_back(testStack);
	CardStacks.push_back(testStack2);


	//make card deck factory later
	card0 = new Card(SPADES, 1, "PixelCard_Assets/Cards/Spades/Card_AceSpade_Big.png", 0, 0, true);
	card1 = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_2Spades.png",100,100, true);
	card2 = new Card(SPADES, 3, "PixelCard_Assets/Cards/Spades/Card_3Spades.png", 100, 132, true);
	card3 = new Card(SPADES, 4, "PixelCard_Assets/Cards/Spades/Card_4Spades.png", 100, 164, true);
	card4 = new Card(SPADES, 5, "PixelCard_Assets/Cards/Spades/Card_5Spades.png", 100, 196, true);
	card5 = new Card(SPADES, 6, "PixelCard_Assets/Cards/Spades/Card_6Spades.png", 100, 228, true);

	testStack->addToStack(card3);
	testStack->addToStack(card4);
	testStack->addToStack(card5);
	testStack->addToStack(card0);



	testStack2->addToStack(card1);
	testStack2->addToStack(card2);

	testStack->transferStack(card0, testStack2);

	testStack2->transferStack(card0, testStack);

	testStack->transferStack(card0, testStack2);




}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);


	// chuck in mouse class most of this latter
	switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT) {
				Game::mouseDown = true;
				int x, y;
				SDL_GetMouseState(&x, &y);
				mousePos.x = x;
				mousePos.y = y;

				//card0->Collide(&mousePos, false);


				//temp jury rig
				bool stupid = testStack->Collide(&mousePos, MouseStackEnable);
				bool stupid2 = testStack2->Collide(&mousePos, MouseStackEnable);
				
				if (stupid) {
					collideStack = testStack;
				}else if(stupid2) {
					collideStack = testStack2;
				}




				std::cout << "x: " << x << "y: " << y;
				std::cout << "pain\n";
			}
			break;
		}
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) {
				Game::mouseDown = false;

				int x, y;
				SDL_GetMouseState(&x, &y);
				mousePos.x = x;
				mousePos.y = y;

				

				//temp jury rig
				bool stupid = testStack->Collide(&mousePos, BasicCollision);
				std::cout << "ULG STACK 1 COLLIDE: "<<stupid<<std::endl;
				bool stupid2= testStack2->Collide(&mousePos, BasicCollision);
				std::cout << "ULG STACK 2 COLLIDE: " << stupid2 << std::endl;


				if (stupid) {
					collideStack = testStack;
					collideStack->transferStack(collideStack->mouseCardStack, testStack2);
				}
				else if (stupid2) {
					collideStack = testStack2;
					collideStack->transferStack(collideStack->mouseCardStack, testStack);
				}

				collideStack = nullptr;
				testStack->ReleaseMouse();
				testStack2->ReleaseMouse();
				//make check collision with stack top cards
			

				
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
	
}

//later in deck class handle all the card shit
void Game::update(){

	testStack->update();
	testStack2->update();


}
// render order matters this is to be handled by stacks
void Game::render(){
	SDL_RenderClear(renderer);
	testStack->Render();
	testStack2->Render();

	testStack->RenderMouseStack();
	testStack2->RenderMouseStack();

	
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned." << std::endl;
}
