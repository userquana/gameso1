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

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xP;
	destRect.y = yP;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

};
void obj::RenderO()
{
	SDL_RenderCopy(game::renderer, objtex, &srcRect, &destRect);
};
