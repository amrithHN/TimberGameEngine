#include <stdio.h>
#include "SDL.h"
#include "TimberEngine2D.h" 

TimberEngine* game = nullptr;

int main(int argc,char* argv[]) {

	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window* window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,600,400,SDL_WINDOW_SHOWN);
	//SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);

	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	//SDL_Delay(3000);


	game = new TimberEngine();

	game->init("TimberGameEngine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,false);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;

	while (game->running()) {

		frameStart = SDL_GetTicks(); //32bit max ise 64bit version in future!

		game->handleEvents();
		game->render();
		game->update();

		frameTime = SDL_GetTicks() - frameStart;
		std::cout << frameTime << std::endl;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay-frameTime);
	}

	game->clean();



	return 0;
}