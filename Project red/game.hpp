#ifndef game_hpp
#define game_hpp
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class game {
public:
	game();
	~game();
	void init(const char* title, int xP, int yP, int w, int h, bool fullscreen);
	void handelEvents();
	void update();
	void render();
	void clean();
	bool rungame()
	{
		return running;
	};

	static SDL_Renderer* renderer;


private:
	int cnt = 0;
	bool running;
	SDL_Window* window;

};


#endif /* game_hpp */
