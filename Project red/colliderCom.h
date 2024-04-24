#pragma once
#include <string>
#include <SDL.h>
#include "ECS/component.h"

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
		collider.x = static_cast<int>(transform->post.x);
		collider.y = static_cast<int>(transform->post.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

private:

};