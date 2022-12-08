#pragma once
#include "TimberEngine2D.h"

class GameObject {

public:
	void load(int x, int y, int width , int height, int TextureID);
	void draw();
	void update();
	void clean();
protected:
	int x;
	int y;
};


class Player : public GameObject
{
public:
	void draw();
	void update();
	void clean();
};


