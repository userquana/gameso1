#pragma once
#include "component.h"
#include "../vector2D.h"

class TransformComponent : public Component
{
public:
	
	vector2D post;


	TransformComponent()
	{
		post.x = 0.0f;
		post.y = 0.0f;
	}

	TransformComponent(float x, float y)
	{
		post.x = x;
		post.y = y;
	}
	void update() override
	{
	}
};