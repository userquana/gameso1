#pragma once
#include "game.hpp"
#include "ECS/loadECS.h"
#include "ECS/component.h"

class keycontrol : public Component
{
public:
	TransformComponent* transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (game::event.type == SDL_KEYDOWN)
		{
			switch (game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velco.y = -1;
				break;
			case SDLK_a:
				transform->velco.x = -1;
				break;
			case SDLK_d:
				transform->velco.x = 1;
				break;
			case SDLK_s:
				transform->velco.y = 1;
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
				break;
			case SDLK_a:
				transform->velco.x = 0;
				break;
			case SDLK_d:
				transform->velco.x = 0;
				break;
			case SDLK_s:
				transform->velco.y = 0;
				break;
			default:
				break;
			}
		}

	}

};
