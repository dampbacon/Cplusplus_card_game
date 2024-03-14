#include "GameBoard.hpp"
#include "Game.hpp"
namespace gameObjects {

	GameBoard::GameBoard()
	{
		Cards = std::vector <Card*>(52);

		Cards[0]= new Card(HEARTS, 1, "PixelCard_Assets/Cards/Hearts/Card_AceHearts_Big.png", 0, 0, true);
		Cards[1] = new Card(HEARTS, 2, "PixelCard_Assets/Cards/Hearts/Card_2Hearts_Black.png", 0, 0, true);
		Cards[2] = new Card(HEARTS, 3, "PixelCard_Assets/Cards/Hearts/Card_3Hearts.png", 0, 0, true);
		Cards[3] = new Card(HEARTS, 4, "PixelCard_Assets/Cards/Hearts/Card_4Hearts.png", 0, 0, true);
		Cards[4] = new Card(HEARTS, 5, "PixelCard_Assets/Cards/Hearts/Card_5Hearts.png", 0, 0, true);
		Cards[5] = new Card(HEARTS, 6, "PixelCard_Assets/Cards/Hearts/Card_6Hearts.png", 0, 0, true);
		Cards[6] = new Card(HEARTS, 7, "PixelCard_Assets/Cards/Hearts/Card_7Hearts.png", 0, 0, true);
		Cards[7] = new Card(HEARTS, 8, "PixelCard_Assets/Cards/Hearts/Card_8Hearts.png", 0, 0, true);
		Cards[8] = new Card(HEARTS, 9, "PixelCard_Assets/Cards/Hearts/Card_9Hearts.png", 0, 0, true);
		Cards[9] = new Card(HEARTS, 10, "PixelCard_Assets/Cards/Hearts/Card_10Hearts.png", 0, 0, true);
		Cards[10] = new Card(HEARTS, 11, "PixelCard_Assets/Cards/Hearts/Card_JackHearts.png", 0, 0, true);
		Cards[11] = new Card(HEARTS, 12, "PixelCard_Assets/Cards/Hearts/Card_QueenHeart.png", 0, 0, true);
		Cards[12] = new Card(HEARTS, 13, "PixelCard_Assets/Cards/Hearts/Card_KingHeart.png", 0, 0, true);


		s0 = new Stack(0);
		s1 = new Stack(1);
		s2 = new Stack(2);

		s3 = new Stack(3);
		s4 = new Stack(4);
		s5 = new Stack(5);

		s6 = new Stack(6);

		CardStacks.push_back(s0);

		CardStacks.push_back(s1);

		CardStacks.push_back(s2);

		CardStacks.push_back(s3);
		CardStacks.push_back(s4);
		CardStacks.push_back(s5);
		CardStacks.push_back(s6);



		CardStacks[6]->addToStack(Cards[0]);
		CardStacks[6]->addToStack(Cards[1]);
		CardStacks[6]->addToStack(Cards[2]);
		CardStacks[6]->addToStack(Cards[3]);
		CardStacks[6]->addToStack(Cards[4]);
		CardStacks[6]->addToStack(Cards[5]);
		CardStacks[6]->addToStack(Cards[6]);
		CardStacks[6]->addToStack(Cards[7]);
		CardStacks[6]->addToStack(Cards[8]);
		CardStacks[6]->addToStack(Cards[9]);
		CardStacks[6]->addToStack(Cards[10]);
		CardStacks[6]->addToStack(Cards[11]);
		CardStacks[6]->addToStack(Cards[12]);




	}

	GameBoard::~GameBoard()
	{
	}

	void GameBoard::render(){
		for (auto const& i : CardStacks) {
			i->Render();
		}
		for (auto const& i : CardStacks) {
			i->RenderMouseStack();
		}
	}
	void GameBoard::update(){
		for (auto const& i : CardStacks) {
			i->update();
		}
	}



	void GameBoard::handleEvents(SDL_Event event) {
		static Stack* collideStack = nullptr; // Initialize outside the switch statement

		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				Game::mouseDown = true;
				int x, y;
				SDL_GetMouseState(&x, &y);
				Game::mousePos.x = x;
				Game::mousePos.y = y;

				for (Stack* stack : CardStacks) {
					bool collision = stack->Collide(&Game::mousePos, MouseStackEnable);
					if (collision) {
						collideStack = stack;
						break;
					}
				}

				std::cout << "x: " << x << "y: " << y;
				std::cout << "pain\n";
			}
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				Game::mouseDown = false;

				int x, y;
				SDL_GetMouseState(&x, &y);
				Game::mousePos.x = x;
				Game::mousePos.y = y;

				// Iterate through the CardStacks array to check collision with each stack
				for (Stack* stack : CardStacks) {
					bool collision = stack->Collide(&Game::mousePos, BasicCollision);
					if (collision && collideStack != nullptr) {
						collideStack->transferStack(collideStack->mouseCardStack, stack);
						break;
					}
				}
				collideStack = nullptr; // Reset collideStack after usage

				for (auto const& i : CardStacks) {
					i->ReleaseMouse();
				}
			}
			break;
		}
		}

	}

}