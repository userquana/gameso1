#pragma once

struct  animation
{
	int ind;
	int frames;
	int speed;
	animation()
	{}
	animation(int i, int f, int s)
	{
		ind = i;
		frames = f;
		speed = s;
	}
};