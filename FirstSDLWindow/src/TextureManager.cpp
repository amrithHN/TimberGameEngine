#include "TextureManager.h"
#include"SDL_Image.h"


bool TextureManager::load(std::string id, std::string Tex, SDL_Renderer* renderer) {

	SDL_Surface* surface = IMG_Load(Tex.c_str());
	if (surface == 0)
		return false;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (texture)
	{
		texture_map[id] = texture;
		return true;
	}
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {


	SDL_Rect srcRect,desRect;
	srcRect.x = srcRect.y = 0;

	srcRect.w = desRect.w = width;
	srcRect.h = desRect.h = height;

	desRect.x = x;
	desRect.y = y;

	SDL_RenderCopyEx(renderer,texture_map[id],&srcRect,&desRect,0,0,flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip) {


	SDL_Rect srcRect, desRect;
	srcRect.w = width;
	srcRect.h = height;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow-1; // not sure??

	desRect.x = x;
	desRect.y = y;
	desRect.w = width;
	desRect.h = height;

	SDL_RenderCopyEx(renderer, texture_map[id], &srcRect, &desRect, 0, 0, flip);
}

typedef TextureManager TheTextureManager;
TextureManager* TextureManager::instance;
