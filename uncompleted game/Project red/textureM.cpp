#include "texture.hpp"

SDL_Texture* texture_M::LoadTexture(const char* texture1)
{
	SDL_Surface* tempSur = IMG_Load(texture1);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(game::renderer, tempSur);
	SDL_FreeSurface(tempSur);

	return tex;
	// tao texture cho nhan vat
}

void texture_M::ve(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(game::renderer, tex, &src, &dest,NULL, NULL, flip);
}