#pragma once
#include "game.hpp"
class obj {
public:
	obj(const char* texturesheet, int x, int y); // render linh tinh trong game
	~obj();

	void UpdateO();
	// update vat the
	void RenderO();

private:
	
	int xP, yP;					// vi tri texure spwan
	SDL_Texture* objtex;
	SDL_Rect srcRect, destRect;

};