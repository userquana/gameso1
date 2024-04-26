#pragma once
#include "ECS/loadECS.h"
#include <SDL.h>
#include "ECS/Sprite.h"
#include <string>
#include "ECS/collidercomponent.h"

class tileComponent : public Component
{
public:
	TransformComponent* transfrom;
	spritecomponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path;

	tileComponent() = default;

	tileComponent(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;
		switch (tileID)
		{
		case 0:
			path = "assets/khong.PNG";
			break;
		case 1:
			path = "assets/co.PMG";
			break;
		case 2:
			path = "assets/cloud.PNG";
		case 3:
			path = "assets/sky.PNG";
			break;
		default:
			break;
		}


	}

	void init() override
	{
		entity->addcomponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transfrom = &entity->getComponent<TransformComponent>();

		entity->addcomponent<spritecomponent>(path);
		sprite = &entity->getComponent<spritecomponent>();
	
	}
};