#include "Game.h"


void Game::on_event(SDL_Event* Event)
{

}

bool Game::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		spdlog::error("Some error message with arg: []", 1);
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		spdlog::error("Unable to Init hinting:", SDL_GetError());
	}
	return false;

	if ((game_window = SDL_CreateWindow(
		"SDL Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
		) == NULL) 
	{
		spdlog::error("Unable to create SDL Window:", SDL_GetError());
		return false;
	}

	//primary_surface = SDL_GetWindowSurface(window);

	if ((game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED)) == NULL) 
	{
		spdlog::error("Unable to create renderer");
		return false;
	}

	SDL_SetRenderDrawColor(game_renderer, 0x00, 0x00, 0x00, 0xFF);

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		spdlog::error("Unable to init SDL_image: %s", IMG_GetError());
	}
	
	return true;

}



void Game::loop()
{

}

void Game::render()
{
	SDL_RenderClear(game_renderer);

	SDL_RenderPresent(game_renderer);
}

void Game::cleanup()
{
	if (game_renderer) 
	{
		SDL_DestroyRenderer(game_renderer);
		game_renderer = NULL;
	}

	if (game_window)
	{
		SDL_DestroyWindow(game_window);
		game_window = NULL;
	}

	IMG_Quit();
	SDL_Quit();

}

int Game::execute(int argc, char* argv[])
{
	if (!init()) return 0;

	SDL_Event event;

	while (Running)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			


		}
	}

	cleanup();

	return 1;
}


int Game::get_window_width()
{
	return WindowWidth;
}

int Game::get_window_height()
{
	return WindowHeight;
}
