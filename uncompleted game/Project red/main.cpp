#include "game.hpp"
#undef main


game* Game = nullptr;
int main(int argc, const char* argv[]) {

	const int fps = 60;
	const int fpsdelay = 1000 / fps;

	Uint32 frame1;
	int frametime;

	Game = new game();

	Game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 640, false);

	while (Game->rungame()) {

		frame1 = SDL_GetTicks();

		Game->handelEvents();
		Game->update();
		Game->render();

		frametime = SDL_GetTicks() - frame1;

		if (fpsdelay > frametime) {
			SDL_Delay(fpsdelay - frametime); // delay fps cho smooth 
		}
	}

	Game->clean();

	return 0;
}