#include "StackUtils.hpp"
using namespace cardStacks::stackRules;





bool cardStacks::stackRules::Foundation(const std::vector<Card*>& cards) {
	return (2 % 2 == 0);
}

bool cardStacks::stackRules::Tableau(const std::vector<Card*>& cards) {
	return (1 > 0);
}



bool cardStacks::stackRules::defaultFunction(const std::vector<Card*>& cards)
{
	return true;
}
