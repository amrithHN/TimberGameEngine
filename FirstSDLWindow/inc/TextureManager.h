#pragma once
#include<string>
#include <map>
#include"SDL.h"

class TextureManager
{
public:
	bool load(std::string id, std::string Tex,SDL_Renderer* renderer); // load to memory (sprite or animated sprite sheet or tileset) and assign an texture ID 
	void Update(std::string id, SDL_Renderer* renderer); // use ID to update texture
	void draw(std::string id,int x, int y, int width, int height, SDL_Renderer* renderer,SDL_RendererFlip=SDL_FLIP_NONE); // to load a graphic
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE); // to animate
	static TextureManager* Instance() {
		if (instance == 0)
			instance = new TextureManager;
		return instance;
	}
	
private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> texture_map;
	static TextureManager* instance;
	

};

