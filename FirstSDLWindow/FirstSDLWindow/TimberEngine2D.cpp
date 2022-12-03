#include"TimberEngine2D.h"
#include"SDL_image.h"
SDL_Texture* playerTexture;
SDL_Rect SrcRect, DesRect;


TimberEngine::TimberEngine(){

	std::cout << "Timber engine started..."<<std::endl;
}

TimberEngine::~TimberEngine(){ 

	std::cout << "Timber engine Died :("<<std::endl;
}
void TimberEngine::init(const char* title, int x, int y, int width, int height, bool fulllscreen) {

	bool flags = 0;
	if (fulllscreen)
		flags = SDL_WINDOW_FULLSCREEN;


	if (SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		std::cout << "SDL subsystems init done.." << std::endl;
		window = SDL_CreateWindow(title,x,y,width,height,flags); //create window
		if (window)
		{
			std::cout << "Window created..." << std::endl;
			isRunning = true;
			renderer = SDL_CreateRenderer(window, -1, 0); 
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //draw white color in window
				std::cout << "Renderer created..." << std::endl;
			}
		}
		else
			isRunning = false;
	}
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer,tmpSurface);
	SDL_FreeSurface(tmpSurface);

}

void TimberEngine::update() {
	static int cnt = 0;

	DesRect.w = 64;
	DesRect.h = 64;

	cnt++;
	DesRect.x = cnt;

}

void TimberEngine::render() {


	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &DesRect);
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