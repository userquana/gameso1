#pragma once
#include "component.h"
#include "../vector2D.h"

class TransformComponent : public Component
{
public:

	vector2D post;
	vector2D velco;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;


	TransformComponent()
	{
		post.Zero();
	}
	TransformComponent(int sc)
	{
		post.Zero();
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		post.Zero();
	}
	TransformComponent(float x, float y, int h, int w, int sc)
	{
		post.x = x;
		post.y = y;
		height = h;
		width = w;
		scale = sc;
	}
	void init() override
	{
		velco.Zero();
	}
	void update() override
	{
		post.x += velco.x * speed;
		post.y += velco.y * speed;
	}
};