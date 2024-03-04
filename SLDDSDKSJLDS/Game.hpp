#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>


class Game {
public:
	Game();
	~Game(); // deconstructor

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };
	bool mouseDown;
	SDL_Point mousePos;

	static SDL_Renderer* renderer;

private:
	bool isRunning = false;
	SDL_Window  *window;
	int count = {};
};
