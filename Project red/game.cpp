#include "game.hpp"
#include "texture.hpp"
#include"map.h"	
#include "ECS/loadECS.h"
#include "ECS/component.h"
#include "vector2d.h"

map* Map;
SDL_Renderer* game::renderer = nullptr;

manage manager;
auto& Player(manager.addEntity());

game::game()
{}

game::~game()
{}

void game::init(const char* title, int xP, int yP, int w, int h, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << " chay" << std::endl;
		window = SDL_CreateWindow(title, xP, yP, w, h, flags);
			if (window)
			{
				std::cout << "chay roi" << std::endl;
			}
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer) 
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "render chay" << std::endl;
			}
			else { running = false; }

			running = true;
	}
	Map = new map();
	Player.addcomponent<TransformComponent>();
	Player.addcomponent<spritecomponent>("assets/player1.png");
}

void game::handelEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;

	default:
		break;
	}
}

void game::update()
{
	// update vat the o day
	manager.refresh();
	manager.update();
	Player.getComponent<TransformComponent>().post.Add(vector2D(5, 0));
	if (Player.getComponent<TransformComponent>().post.x > 100)
	{
		Player.getComponent<spritecomponent>().setTex("assets/player2.png");
	}
}

void game::render()
{// render o day
	SDL_RenderClear(renderer);
	Map->drawmap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void game::clean()
{	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game clear" << std::endl;
}