#include "gameobj.h"
#include"texture.hpp"
obj::obj(const char* texturesheet, int x, int y)
{
	objtex = texture_M::LoadTexture(texturesheet);

	xP = x;
	yP = y;

};
void obj::UpdateO()
{	
	xP++;
	yP++;

	srcRect.h = 100;
	srcRect.w = 100;
	srcRect.x = 500;
	srcRect.y = 400;

	destRect.x = xP;
	destRect.y = yP;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

};
void obj::RenderO()
{
	SDL_RenderCopy(game::renderer, objtex, &srcRect, &destRect);
};
