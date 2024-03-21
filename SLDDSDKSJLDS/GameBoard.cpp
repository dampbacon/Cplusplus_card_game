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

		Cards[13] = new Card(SPADES, 1, "PixelCard_Assets/Cards/Spades/Card_AceSpade_Big.png", 0, 0, true);
		Cards[14] = new Card(SPADES, 2, "PixelCard_Assets/Cards/Spades/Card_2Spades.png", 0, 0, true);
		Cards[15] = new Card(SPADES, 3, "PixelCard_Assets/Cards/Spades/Card_3Spades.png", 0, 0, true);
		Cards[16] = new Card(SPADES, 4, "PixelCard_Assets/Cards/Spades/Card_4Spades.png", 0, 0, true);
		Cards[17] = new Card(SPADES, 5, "PixelCard_Assets/Cards/Spades/Card_5Spades.png", 0, 0, true);
		Cards[18] = new Card(SPADES, 6, "PixelCard_Assets/Cards/Spades/Card_6Spades.png", 0, 0, true);
		Cards[19] = new Card(SPADES, 7, "PixelCard_Assets/Cards/Spades/Card_7Spades.png", 0, 0, true);
		Cards[20] = new Card(SPADES, 8, "PixelCard_Assets/Cards/Spades/Card_8Spades.png", 0, 0, true);
		Cards[21] = new Card(SPADES, 9, "PixelCard_Assets/Cards/Spades/Card_9Spades.png", 0, 0, true);
		Cards[22] = new Card(SPADES, 10, "PixelCard_Assets/Cards/Spades/Card_10Spades.png", 0, 0, true);
		Cards[23] = new Card(SPADES, 11, "PixelCard_Assets/Cards/Spades/Card_JackSpade.png", 0, 0, true);
		Cards[24] = new Card(SPADES, 12, "PixelCard_Assets/Cards/Spades/Card_QueenSpade.png", 0, 0, true);
		Cards[25] = new Card(SPADES, 13, "PixelCard_Assets/Cards/Spades/Card_KingSpade.png", 0, 0, true);

		Cards[26] = new Card(CLUBS, 1, "PixelCard_Assets/Cards/Clubs/Card_AceClubs_Big.png", 0, 0, true);
		Cards[27] = new Card(CLUBS, 2, "PixelCard_Assets/Cards/Clubs/Card_2Clubs.png", 0, 0, true);
		Cards[28] = new Card(CLUBS, 3, "PixelCard_Assets/Cards/Clubs/Card_3Clubs.png", 0, 0, true);
		Cards[29] = new Card(CLUBS, 4, "PixelCard_Assets/Cards/Clubs/Card_4Clubs.png", 0, 0, true);
		Cards[30] = new Card(CLUBS, 5, "PixelCard_Assets/Cards/Clubs/Card_5Clubs.png", 0, 0, true);
		Cards[31] = new Card(CLUBS, 6, "PixelCard_Assets/Cards/Clubs/Card_6Clubs.png", 0, 0, true);
		Cards[32] = new Card(CLUBS, 7, "PixelCard_Assets/Cards/Clubs/Card_7Clubs.png", 0, 0, true);
		Cards[33] = new Card(CLUBS, 8, "PixelCard_Assets/Cards/Clubs/Card_8Clubs.png", 0, 0, true);
		Cards[34] = new Card(CLUBS, 9, "PixelCard_Assets/Cards/Clubs/Card_9Clubs.png", 0, 0, true);
		Cards[35] = new Card(CLUBS, 10, "PixelCard_Assets/Cards/Clubs/Card_10Clubs.png", 0, 0, true);
		Cards[36] = new Card(CLUBS, 11, "PixelCard_Assets/Cards/Clubs/Card_Jack.png", 0, 0, true);
		Cards[37] = new Card(CLUBS, 12, "PixelCard_Assets/Cards/Clubs/Card_Queen.png", 0, 0, true);
		Cards[38] = new Card(CLUBS, 13, "PixelCard_Assets/Cards/Clubs/Card_King.png", 0, 0, true);

		Cards[39] = new Card(DIAMONDS, 1, "PixelCard_Assets/Cards/Diamonds/Card_ClubOfDiamond_Big.png", 0, 0, true);
		Cards[40] = new Card(DIAMONDS, 2, "PixelCard_Assets/Cards/Diamonds/Card_2Diamonds.png", 0, 0, true);
		Cards[41] = new Card(DIAMONDS, 3, "PixelCard_Assets/Cards/Diamonds/Card_3Diamonds.png", 0, 0, true);
		Cards[42] = new Card(DIAMONDS, 4, "PixelCard_Assets/Cards/Diamonds/Card_4Diamonds.png", 0, 0, true);
		Cards[43] = new Card(DIAMONDS, 5, "PixelCard_Assets/Cards/Diamonds/Card_5Diamonds.png", 0, 0, true);
		Cards[44] = new Card(DIAMONDS, 6, "PixelCard_Assets/Cards/Diamonds/Card_6Diamonds.png", 0, 0, true);
		Cards[45] = new Card(DIAMONDS, 7, "PixelCard_Assets/Cards/Diamonds/Card_7Diamonds.png", 0, 0, true);
		Cards[46] = new Card(DIAMONDS, 8, "PixelCard_Assets/Cards/Diamonds/Card_8Diamonds.png", 0, 0, true);
		Cards[47] = new Card(DIAMONDS, 9, "PixelCard_Assets/Cards/Diamonds/Card_9Diamonds.png", 0, 0, true);
		Cards[48] = new Card(DIAMONDS, 10, "PixelCard_Assets/Cards/Diamonds/Card_10Diamonds.png", 0, 0, true);
		Cards[49] = new Card(DIAMONDS, 11, "PixelCard_Assets/Cards/Diamonds/Card_JackDiamond.png", 0, 0, true);
		Cards[50] = new Card(DIAMONDS, 12, "PixelCard_Assets/Cards/Diamonds/Card_QueenDiamond.png", 0, 0, true);
		Cards[51] = new Card(DIAMONDS, 13, "PixelCard_Assets/Cards/Diamonds/Card_KingDiamond.png", 0, 0, true);





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


		//hearts
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

		//spades
		CardStacks[5]->addToStack(Cards[13]);
		CardStacks[5]->addToStack(Cards[14]);
		CardStacks[5]->addToStack(Cards[15]);
		CardStacks[5]->addToStack(Cards[16]);
		CardStacks[5]->addToStack(Cards[17]);
		CardStacks[5]->addToStack(Cards[18]);
		CardStacks[5]->addToStack(Cards[19]);
		CardStacks[5]->addToStack(Cards[20]);
		CardStacks[5]->addToStack(Cards[21]);
		CardStacks[5]->addToStack(Cards[22]);
		CardStacks[5]->addToStack(Cards[23]);
		CardStacks[5]->addToStack(Cards[24]);
		CardStacks[5]->addToStack(Cards[25]);
		//clubs
		CardStacks[4]->addToStack(Cards[26]);
		CardStacks[4]->addToStack(Cards[27]);
		CardStacks[4]->addToStack(Cards[28]);
		CardStacks[4]->addToStack(Cards[29]);
		CardStacks[4]->addToStack(Cards[30]);
		CardStacks[4]->addToStack(Cards[31]);
		CardStacks[4]->addToStack(Cards[32]);
		CardStacks[4]->addToStack(Cards[33]);
		CardStacks[4]->addToStack(Cards[34]);
		CardStacks[4]->addToStack(Cards[35]);
		CardStacks[4]->addToStack(Cards[36]);
		CardStacks[4]->addToStack(Cards[37]);
		CardStacks[4]->addToStack(Cards[38]);
		//diamonds
		CardStacks[3]->addToStack(Cards[39]);
		CardStacks[3]->addToStack(Cards[40]);
		CardStacks[3]->addToStack(Cards[41]);
		CardStacks[3]->addToStack(Cards[42]);
		CardStacks[3]->addToStack(Cards[43]);
		CardStacks[3]->addToStack(Cards[44]);
		CardStacks[3]->addToStack(Cards[45]);
		CardStacks[3]->addToStack(Cards[46]);
		CardStacks[3]->addToStack(Cards[47]);
		CardStacks[3]->addToStack(Cards[48]);
		CardStacks[3]->addToStack(Cards[49]);
		CardStacks[3]->addToStack(Cards[50]);
		CardStacks[3]->addToStack(Cards[51]);















	}

	GameBoard::~GameBoard()
	{
		for (auto card : Cards) {
			delete card;
		}
		for (auto stack : CardStacks) {
			delete stack;
		}
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