#include "ECS/component.h"
#include "ECS/collidercomponent.h"

map* Map;
SDL_Renderer* game::renderer = nullptr;
SDL_Event game::event;
Manager manager;

std::vector<ColliderComponent*> game::colliders;

auto& Player(manager.addEntity());

auto& wall(manager.addEntity());

enum groupLabels :std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemy,
	groupColliders
};



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


	map::loadmap("assets/pixel.map", 32, 32);

	Player.addcomponent<TransformComponent>(4);
	Player.addcomponent<spritecomponent>("assets/test.PNG",true);
	Player.addcomponent<keycontrol>();
	Player.addcomponent<ColliderComponent>();
	Player.addgroup(groupPlayers);

	wall.addcomponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addcomponent<spritecomponent>("assets/khong.png");
	wall.addcomponent<ColliderComponent>();
	wall.addgroup(groupMap);
}

void game::handelEvents()
{
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
	for (auto cc : colliders)
	{
		Collision::AABB(Player.getComponent<ColliderComponent>(), *cc);
	}
}

auto& tiles(manager.getgroup(groupMap));
auto& Players(manager.getgroup(groupPlayers));
auto& enemies(manager.getgroup(groupEnemy));
void game::render()
{// render o day
	SDL_RenderClear(renderer);
	//manager.draw();

	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : Players)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}

	SDL_RenderPresent(renderer);
}

void game::clean()
{	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game clear" << std::endl;
}


void game::addtile(int id, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addcomponent<tileComponent>(x, y, 32, 32, id);
	tile.addgroup(groupMap);
}