#include<stdio.h>
#include "SDL.h"

#include"TimberEngine2D.h" 

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
	
	while (game->running()) {
		game->handleEvents();
		game->render();
		game->update();
	}

	game->clean();



	return 0;
}