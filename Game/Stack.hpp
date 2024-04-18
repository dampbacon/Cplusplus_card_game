#pragma once
#include <vector>
#include "Card.hpp"
#include "Game.hpp"

namespace cardStacks {
	class Stack;
}

namespace cardStacks {

	typedef bool (*FunctionPtr)(const std::vector<Card*>&, Stack*);

	bool Foundation(const std::vector<Card*>& cards, Stack* target);
	bool Tableau(const std::vector<Card*>& cards, Stack* target);
	bool defaultFunction(const std::vector<Card*>& cards, Stack* target);


	enum collisionType {
		MouseStackEnable,
		MouseButtonRelease,
		BasicCollision
	};

	enum CardStackType {
		SameSuitAsc,
		AlternatingColorDsc
	};

	enum StackType {
		PLAYSTACK,
		DEALSTACK,
		BASESTACK
	};


	class Stack
	{
	public:
		//Stack(int ID);
		Stack(int x, int y);
		Stack();
		virtual ~Stack() = 0;

		std::vector <Card*> CardStack;
		std::vector <Card*> mouseCardStack;

		//ADD STACK HITBOX, STACK TEXTURE AND STACK COLLIDE
		//THIS IS NEEDED TO ITERACT WITH EMPTY STACKS
		SDL_Rect* stackHitBox;
		void Render();
		void RenderMouseStack();
		void update();

		virtual void ReleaseMouse() = 0;
		virtual void addToStack(Card* card) = 0;
		virtual void addToStack(const std::vector<Card*>& cards) = 0;
		virtual void transferStack(const std::vector<Card*>& cards, Stack* destStack, bool FORCE = false) = 0;
		virtual void transferStack(Card* card, Stack* destStack) = 0;
		virtual bool Collide(SDL_Point* mouse, collisionType type) = 0;

		virtual StackType getType() = 0;
		FunctionPtr stackRules = defaultFunction;

	protected:
		int yRenderOffset;

	private:
	};

	class PlayStack : public Stack { // Modified this line
	public:
		PlayStack(int ID, FunctionPtr ptr = defaultFunction, int y=288, int yRenOffset = 32);
		~PlayStack() override;
		int getStackID();

		//used to flip top card if mousestack empty and topcard is not flipped
		void revealTopCard();
		//game logic
		//void canBeAdded(std::vector<Card*>& cards);

		void ReleaseMouse() override;
		void addToStack(Card* card) override;
		void addToStack(const std::vector<Card*>& cards) override;
		void transferStack(const std::vector<Card*>& cards, Stack* destStack, bool FORCE=false) override;
		void transferStack(Card* card, Stack* destStack) override;
		bool Collide(SDL_Point* mouse, collisionType type) override;

		StackType getType() override;



	
	private:
		StackType type;
		int xGridAllignment;
	};



	class DrawPile : public Stack { // Modified this line
	public:
		DrawPile(int x, int y, FunctionPtr ptr = defaultFunction, int yRenOffset = 3);
		~DrawPile() override;
		void shuffleCards();
		void takeAllCards(std::vector<Stack*>& stacks);
		void deal(std::vector<Stack*>& stacks, StackType targetType);
		void returnDealpile();
		void renderDealPile();
		void updateDealPile();

		void ReleaseMouse() override;

		//only render/show top 3 cards
		std::vector <Card*> dealStack;



		StackType getType() override;
		void addToStack(Card* card) override;
		void addToStack(const std::vector<Card*>& cards) override;
		void transferStack(const std::vector<Card*>& cards, Stack* destStack, bool FORCE=false) override;
		void transferStack(Card* card, Stack* destStack) override;
		bool Collide(SDL_Point* mouse, collisionType type) override;
	private:
		StackType type;
	};


	
}
