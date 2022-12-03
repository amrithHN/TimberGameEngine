#ifndef TimberGameEngine
#define TimberGameEngine

#include<iostream>
#include "../include/SDL.h"

class TimberEngine {

public:
	TimberEngine();
	~TimberEngine();

	void init(const char* title,int x,int y, int width,int height,bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};



#endif
