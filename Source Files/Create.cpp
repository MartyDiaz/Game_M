#include "Create.h"

SDL_Window* Create::window(int screen_width, int screen_height)
{
	SDL_Window* created_window = NULL;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		spdlog::error("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Set Texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			spdlog::error("Warning: Linear texture filtering not enabled");
		}
		//Create window
		created_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (created_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			return created_window;
		}
	}
}

SDL_Renderer* Create::renderer(SDL_Window* created_window)
{
	if (created_window == NULL)
	{
		spdlog::error("Passed in NULL window");
	}
	else {
		SDL_Renderer* created_renderer = NULL;
		// create renderer for window
		created_renderer = SDL_CreateRenderer(created_window, -1, SDL_RENDERER_ACCELERATED);
		if (created_renderer == NULL)
		{
			spdlog::error("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}
		else {
			// Initialize renderer coler
			SDL_SetRenderDrawColor(created_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG Loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				spdlog::error("SDL_Image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
			}
			else {
				return created_renderer;
			}
		}
	}
}

std::unique_ptr<Texture_Storage> Create::texture_storage(SDL_Renderer* created_renderer, std::string folder_path)
{
	return std::make_unique<Texture_Storage>(created_renderer, folder_path);
}
