#pragma once
#include "Stack.hpp"

class DrawPile : public Stack {
public:
    DrawPile(int ID) : Stack(ID) {}

    void shuffleDrawPile();

    void Render();

};
