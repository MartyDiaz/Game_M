#ifndef Game_H
#define Game_H

#include "Component.h"
#include "Entity.h"
#include "Manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include "spdlog/spdlog.h"
class Game
{
private:

	bool Running = true;

	SDL_Window* game_window = NULL;
	SDL_Renderer* game_renderer = NULL;
	SDL_Surface* primary_game_surface = NULL;

	static const int WindowWidth = 1024;
	static const int WindowHeight = 768;

private:

	Game();

	void on_event(SDL_Event* Event);

	bool init();

	void loop();

	void render();

	void cleanup();

public:
	
	int execute(int argc, char* argv[]);

public:
	

	static int get_window_width();

	static int get_window_height();

};
#endif
