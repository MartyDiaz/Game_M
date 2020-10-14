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

	if ((window = SDL_CreateWindow(
		"SDL Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
		) == NULL) 
	{
		spdlog::error("Unable to create SDL Window:", SDL_GetError());
		return false;
	}

	//primary_surface = SDL_GetWindowSurface(window);

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL) 
	{
		spdlog::error("Unable to create renderer");
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	return true;

}



void Game::loop()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::cleanup()
{
	if (renderer) 
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	if (window)
	{
		SDL_DestroyWindow(window);
		window = NULL;
	}

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

Game* Game::get_instance()
{
	return nullptr;
}

int Game::get_window_width()
{
	return WindowWidth;
}

int Game::get_window_height()
{
	return WindowHeight;
}
