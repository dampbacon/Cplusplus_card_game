#include "Stack.hpp"
#include <iostream>
#include <vector>

bool cardStacks::Foundation(const std::vector<Card*>& cards, cardStacks::Stack* target) {
    return (2 % 2 == 0);
}

bool cardStacks::Tableau(const std::vector<Card*>& cards, cardStacks::Stack* target) {
   return (1 > 0);
}

bool cardStacks::defaultFunction(const std::vector<Card*>& cards, cardStacks::Stack* target) {
    std::cout << "test\n";
    return true;
}
