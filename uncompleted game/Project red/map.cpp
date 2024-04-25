#include "map.h"
#include "game.hpp"
#include <fstream>

map::map()
{

}

map::~map()
{

}

void map::loadmap(std::string path, int sizeX, int sizeY) 
{
	char tile;
	std::fstream mapfile;
	mapfile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapfile.get(tile);
			game::addtile(atoi(&tile), x * 32, y * 32);
			mapfile.ignore();
		}
	}
	mapfile.close();

}

