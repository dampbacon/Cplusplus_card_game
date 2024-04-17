#include "Stack.hpp"
#include <iostream>
#include <vector>

bool cardStacks::Foundation(const std::vector<Card*>& cards, cardStacks::Stack* target) {
    return true;
}

bool cardStacks::Tableau(const std::vector<Card*>& cards, cardStacks::Stack* target) {
    bool success = false;
    //SDL_assert(!cards.empty());
    //SDL_assert(!target->CardStack.empty());
    
    if (!cards.empty()&&!target->CardStack.empty()
        && cards.front()->getVal() == (target->CardStack.back()->getVal() - 1)
        && target->CardStack.back()->getColor()!=cards.front()->getColor()
        ) {
        std::cout << "FUNCTION POINTER TEST DECENDING BUILD ORDER\n";
        success = true;
    }
    else if (target->CardStack.empty() && !cards.empty() && cards.front()->getVal() == 13) {
        std::cout << "FUNCTION POINTER TEST KING EMPTY PILE\n";
        success = true;

    }
    return success;
}

bool cardStacks::defaultFunction(const std::vector<Card*>& cards, cardStacks::Stack* target) {
    std::cout << "test\n";
    return true;
}
