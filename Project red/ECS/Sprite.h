#pragma once
#include "component.h"
#include <sdl.h>

class spritecomponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:
	spritecomponent() = default;
	spritecomponent(const char* path)
	{
		setTex(path);
	}
	void setTex(const char* path)
	{
		texture = texture_M::LoadTexture(path);
	}
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 50;
		srcRect.w = 64;
		srcRect.h = 64;
		destRect.w = destRect.h = 128;
	}
	void update() override
	{
		destRect.x = (int)transform->post.x;
		destRect.y = (int)transform->post.y;
	}
	void draw() override
	{
		texture_M::ve(texture, srcRect, destRect);
	}


};