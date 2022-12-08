
#include <string>
#include <map>
#include "TimberEngine2D.h"
#include "SDL_image.h"


TimberEngine::~TimberEngine(){ 

	std::cout << "Timber engine Died :("<<std::endl;
}
void TimberEngine::init(std::string title, int x, int y, int width, int height, bool fulllscreen) {

	bool flags = 0;
	if (fulllscreen)
		flags = SDL_WINDOW_FULLSCREEN;


	if (SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		std::cout << "SDL subsystems init done.." << std::endl;
		window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags); //create window
		if (window)
		{
			std::cout << "Window created..." << std::endl;
			isRunning = true;
			renderer = SDL_CreateRenderer(window, -1, 0); 
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0); //draw white color in window
				std::cout << "Renderer created..." << std::endl;
			}
		}
		else
			isRunning = false;
	}
	//Texmanager.load("Animate","assets/cat.png",renderer);
}

void TimberEngine::update() {

	currentFrame = int(((SDL_GetTicks() / 100) % 6));

}

void TimberEngine::render() {


	SDL_RenderClear(renderer);
	//Texmanager.draw("Animate",0,0,125,72,renderer);
	//Texmanager.drawFrame("Animate",150,150,125,72,1,currentFrame,renderer,SDL_FLIP_NONE);
	SDL_RenderPresent(renderer);


}

void TimberEngine::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}

}

bool TimberEngine::running() {

	return (isRunning ? 1 : 0);
}

void TimberEngine::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Window destroyed...";

}