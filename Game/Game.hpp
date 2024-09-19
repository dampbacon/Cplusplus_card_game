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

	static void MouseScale(int &x, int &y);

	bool running() { return isRunning; };

	//mouse stuff
	static bool mouseDown;
	static SDL_Point mousePos;
	//mouseDeltas
	static int deltaX;
	static int deltaY;


	static SDL_Renderer* renderer;

	int getLogicalWidth();
	int getLogicalHeight();

private:
	bool isRunning = false;
	SDL_Window  *window;
	int count = {};

	int LogicalWidth;
	int LogicalHeight; 
};
