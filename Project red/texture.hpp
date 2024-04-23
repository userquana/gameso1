#pragma once

#include "game.hpp"

class texture_M {

public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void ve(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};