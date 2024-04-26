#pragma once
#include "game.hpp"
#include "ECS/loadECS.h"
#include "ECS/component.h"

class keycontrol : public Component
{
public:
	TransformComponent* transform;
	spritecomponent* sprite;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<spritecomponent>();
	
	
	}

	void update() override
	{
		if (game::event.type == SDL_KEYDOWN)
		{
			switch (game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velco.y = -1;
				sprite->Play("walk");
				break;
			case SDLK_a:
				transform->velco.x = -1;
				sprite->Play("walk");
				sprite->spriteFllip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				transform->velco.x = 1;
				sprite->Play("walk");
				break;
			case SDLK_s:
				transform->velco.y = 1;
				sprite->Play("walk");
				break;
			default:
				break;
			}
		}
		if (game::event.type == SDL_KEYUP)
		{
			switch (game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velco.y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_a:
				transform->velco.x = 0;
				sprite->Play("Idle");
				sprite->spriteFllip = SDL_FLIP_NONE;
				break;
			case SDLK_d:
				transform->velco.x = 0;
				sprite->Play("Idle");
				break;
			case SDLK_s:
				transform->velco.y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_ESCAPE:
				game::isrunning = false;
			default:
				break;
			}
		}

	}

};
