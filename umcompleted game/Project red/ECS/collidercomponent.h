#pragma once
#include "ECS/component.h"
#include <string>
#include "titleComponent.h"
#include "game.hpp"
#include "component.h"
#include <vector>



class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
		std::string tag;
	TransformComponent* transform;


	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addcomponent<TransformComponent>();
		}		
		transform = &entity->getComponent<TransformComponent>();
	
		game::colliders.push_back(this);
	
	}
	void update() override
	{
		collider.x = transform->post.x;
		collider.y = transform->post.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height* transform->scale;
	}

};