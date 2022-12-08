#pragma once

#include<iostream>
#include "SDL.h"
#include"TextureManager.h"

class TimberEngine{

public:
	
	~TimberEngine();

	void init(std::string title,int x,int y, int width,int height,bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	int currentFrame;
	//TextureManager Texmanager;

};

