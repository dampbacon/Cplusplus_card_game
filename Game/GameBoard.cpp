#include "GameBoard.hpp"
#include "Game.hpp"
using namespace cardStacks;
namespace gameObjects {

	GameBoard::GameBoard()
	{


		//this is going to be our fake mutex
		//LOCK ALL INPUT WHILE ANIMATIONS HAPPEN EVEN IF VERY VERY FAST
		ANIMATION_LOCK = false;

		indicator = TempSolvedIndicator("solved.png", 200, 500, false);



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


		drawPile = new cardStacks::DrawPile(10, 10);

		button1 = tempButton(800,200);
		button2 = tempButton(800, 400);


		s0 = new cardStacks::PlayStack(0, cardStacks::Tableau);
		s1 = new cardStacks::PlayStack(1, cardStacks::Tableau);
		s2 = new cardStacks::PlayStack(2, cardStacks::Tableau);
		s3 = new cardStacks::PlayStack(3, cardStacks::Tableau);
		s4 = new cardStacks::PlayStack(4, cardStacks::Tableau);
		s5 = new cardStacks::PlayStack(5, cardStacks::Tableau);
		s6 = new cardStacks::PlayStack(6, cardStacks::Tableau);

		d0 = new cardStacks::PlayStack(3, cardStacks::Foundation,10,0);
		d1 = new cardStacks::PlayStack(4, cardStacks::Foundation,10,0);
		d2 = new cardStacks::PlayStack(5, cardStacks::Foundation,10,0);
		d3 = new cardStacks::PlayStack(6, cardStacks::Foundation,10,0);

		finalStacks.push_back(d0);
		finalStacks.push_back(d1);
		finalStacks.push_back(d2);
		finalStacks.push_back(d3);

		//tableau
		cardStacks.push_back(s0);
		cardStacks.push_back(s1);
		cardStacks.push_back(s2);
		cardStacks.push_back(s3);
		cardStacks.push_back(s4);
		cardStacks.push_back(s5);
		cardStacks.push_back(s6);
		//temp
		playStacks.push_back(s0);
		playStacks.push_back(s1);
		playStacks.push_back(s2);
		playStacks.push_back(s3);
		playStacks.push_back(s4);
		playStacks.push_back(s5);
		playStacks.push_back(s6);


		//foundations
		cardStacks.push_back(d0);
		cardStacks.push_back(d1);
		cardStacks.push_back(d2);
		cardStacks.push_back(d3);
		//deck
		cardStacks.push_back(drawPile);


		//hearts
		cardStacks[6]->addToStack(Cards[0]);
		cardStacks[6]->addToStack(Cards[1]);
		cardStacks[6]->addToStack(Cards[2]);
		cardStacks[6]->addToStack(Cards[3]);
		cardStacks[6]->addToStack(Cards[4]);
		cardStacks[6]->addToStack(Cards[5]);
		cardStacks[6]->addToStack(Cards[6]);
		cardStacks[6]->addToStack(Cards[7]);
		cardStacks[6]->addToStack(Cards[8]);
		cardStacks[6]->addToStack(Cards[9]);
		cardStacks[6]->addToStack(Cards[10]);
		cardStacks[6]->addToStack(Cards[11]);
		cardStacks[6]->addToStack(Cards[12]);

		//spades
		cardStacks[5]->addToStack(Cards[13]);
		cardStacks[5]->addToStack(Cards[14]);
		cardStacks[5]->addToStack(Cards[15]);
		cardStacks[5]->addToStack(Cards[16]);
		cardStacks[5]->addToStack(Cards[17]);
		cardStacks[5]->addToStack(Cards[18]);
		cardStacks[5]->addToStack(Cards[19]);
		cardStacks[5]->addToStack(Cards[20]);
		cardStacks[5]->addToStack(Cards[21]);
		cardStacks[5]->addToStack(Cards[22]);
		cardStacks[5]->addToStack(Cards[23]);
		cardStacks[5]->addToStack(Cards[24]);
		cardStacks[5]->addToStack(Cards[25]);
		//////clubs
		cardStacks[4]->addToStack(Cards[26]);
		cardStacks[4]->addToStack(Cards[27]);
		cardStacks[4]->addToStack(Cards[28]);
		cardStacks[4]->addToStack(Cards[29]);
		cardStacks[4]->addToStack(Cards[30]);
		cardStacks[4]->addToStack(Cards[31]);
		cardStacks[4]->addToStack(Cards[32]);
		cardStacks[4]->addToStack(Cards[33]);
		cardStacks[4]->addToStack(Cards[34]);
		cardStacks[4]->addToStack(Cards[35]);
		cardStacks[4]->addToStack(Cards[36]);
		cardStacks[4]->addToStack(Cards[37]);
		cardStacks[4]->addToStack(Cards[38]);
		////diamonds
		cardStacks[3]->addToStack(Cards[39]);
		cardStacks[3]->addToStack(Cards[40]);
		cardStacks[3]->addToStack(Cards[41]);
		cardStacks[3]->addToStack(Cards[42]);
		cardStacks[3]->addToStack(Cards[43]);
		cardStacks[3]->addToStack(Cards[44]);
		cardStacks[3]->addToStack(Cards[45]);
		cardStacks[3]->addToStack(Cards[46]);
		cardStacks[3]->addToStack(Cards[47]);
		cardStacks[3]->addToStack(Cards[48]);
		cardStacks[3]->addToStack(Cards[49]);
		cardStacks[3]->addToStack(Cards[50]);
		cardStacks[3]->addToStack(Cards[51]);

	}

	GameBoard::~GameBoard()
	{
		for (auto card : Cards) {
			delete card;
		}
		for (auto stack : cardStacks) {
			delete stack;
		}
	}

	void GameBoard::render(){
		for (auto const& i : cardStacks) {
			i->Render();
		}
		//drawPile->Render();
		drawPile->renderDealPile();
		for (auto const& i : cardStacks) {
			i->RenderMouseStack();
		}

		button1.render();
		button2.render();
		indicator.Render();
	}
	bool GameBoard::checkWinState()
	{
		for (Stack* i : playStacks) {
			for (Card* j : i->CardStack) {
				if (!j->faceUp) {
					std::cout << "########\nNOT SOLVED\n########\n";
					solved = false;
					return false;
				}
			}
		}
		std::cout << "########\nsolved\n########\n";
		solved = true;
		return true;
	}


	void GameBoard::update(){
		for (auto const& i : cardStacks) {
			i->update();
		}
		drawPile->updateDealPile();

		if (solved) {
			solved = false;
			drawPile->takeAllCards(cardStacks);
			drawPile->sortCardsBySuitAndValue();
			for (auto i : drawPile->CardStack) {
				i->setFaceUp();
				i->setDraggable(false);
			}
			
			int counter = 0;
			int currentStack = 0;
			for (auto i : drawPile->CardStack) {
				finalStacks[currentStack]->addToStack(i);
				counter += 1;
				if (counter>0 && counter % 13 == 0 && currentStack<3) {
					currentStack += 1;
				}
				
			}
			drawPile->CardStack.clear();

			for (auto i : finalStacks) {
				i->CardStack.back()->setDraggable(true);
			}
			indicator.Show();
			std::cout << drawPile->CardStack.size();
		}

		
	}



	void GameBoard::handleEvents(SDL_Event event) {
		static Stack* collideStack = nullptr; // Initialize outside the switch statement

		/*
		NOTE TO SELF
		
		MAKE SURE TO USE ANIMATION LOCK ON ALLLLLLLLLLLLLLLLL OF THIS
		
		
		*/


		switch (event.type) {
			case SDL_MOUSEBUTTONDOWN: {
				if (event.button.button == SDL_BUTTON_LEFT) {
					Game::mouseDown = true;
					int x, y;
					SDL_GetMouseState(&x, &y);
					Game::mousePos.x = x;
					Game::mousePos.y = y;

					for (Stack* stack : cardStacks) {
						bool collision = stack->Collide(&Game::mousePos, MouseStackEnable);
						if (collision) {
							collideStack = stack;
							break;
						}
					}

					std::cout << "x: " << x << "y: " << y;
					std::cout << "pain\n";
				}

				if (button1.collide(&Game::mousePos)) {
					drawPile->takeAllCards(cardStacks);
				}

				if (button2.collide(&Game::mousePos)) {
					/*for (auto i : playStacks) {
						i->stackRules = defaultFunction;
						std::cout << "++++++++++++\n";
						std::cout << "RULE CHANGED\n";
						std::cout << "++++++++++++\n";
					
					}*/
					
					std::cout << "TESTING DEALING FUNC\n";
					indicator.Hide();
					drawPile->deal(playStacks,finalStacks);

					/*
					std::cout << "TESTING Shuffle FUNC\n";
					drawPile->shuffleCards();
					*/

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
					for (Stack* stack : cardStacks) {
						bool collision = stack->Collide(&Game::mousePos, BasicCollision);
						if (collision && collideStack != nullptr) {
							collideStack->transferStack(collideStack->mouseCardStack, stack);
							checkWinState();
							break;
						}
						else {
							//std::cout << "shit\n";
						}
					}
					collideStack = nullptr; // Reset collideStack after usage

					for (auto const& i : cardStacks) {
						i->ReleaseMouse();
					}

				}
				break;
			}
		}

		
	}

}