#pragma once
#include "component.h"
#include <sdl.h>
#include "texture.hpp"
#include "animation.h"
#include <map>

class spritecomponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animate = false;
	int frames = 0;
	int speed = 100;

public:

	int animindex = 0;

	std::map <const char*, animation> Animation;

	SDL_RendererFlip spriteFllip = SDL_FLIP_NONE;

	spritecomponent() = default;
	spritecomponent(const char* path)
	{
		setTex(path);
	}
	spritecomponent(const char* path, bool isanimated)
	{
		animate = isanimated;

		animation idle = animation(0,3,100);
		animation walk = animation(1, 8, 100);
		Animation.emplace("Idle", idle);
		Animation.emplace("walk", walk);
		
		play("Idle");

		setTex(path);
	}
	~spritecomponent()
	{
		SDL_DestroyTexture(texture);
	}
	void setTex(const char* path)
	{
		texture = texture_M::LoadTexture(path);
	}
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}
	void update() override
	{
		if (animate)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animindex * transform->height;


		destRect.x = static_cast<int>(transform->post.x);
		destRect.y = static_cast<int>(transform->post.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}
	void draw() override
	{
		texture_M::ve(texture, srcRect, destRect, spriteFllip);
	}

	void play(const char* aniName)
	{
		frames = Animation[aniName].frames;
		animindex = Animation[aniName].ind;
		speed = Animation[aniName].speed;
	}



};