#pragma once

#include "game.hpp"

class map
{
public:

	map();
	~map();

	void loadmap(int a[20][25]);
	void drawmap();

private: 

	SDL_Rect src, dest;
	SDL_Texture* cloud;
	SDL_Texture* co;
	SDL_Texture* khong;
	SDL_Texture* sky;

	int m[20][25];

};