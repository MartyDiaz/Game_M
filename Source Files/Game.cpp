#include "Game.h"


Game::Game()
{
	if (!init_window())
	{
		spdlog::error("Problem initializing game window");
	}
}

Game::~Game()
{
	if (renderer_)
	{
		SDL_DestroyRenderer(renderer_);
		renderer_ = NULL;
	}

	if (window_)
	{
		SDL_DestroyWindow(window_);
		window_ = NULL;
	}
	IMG_Quit();
	SDL_Quit();
}

bool Game::init_window()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		spdlog::error("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set Texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			spdlog::error("Warning: Linear texture filtering not enabled");
		}

		//Create window
		window_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_, SCREEN_HEIGHT_, SDL_WINDOW_SHOWN);
		if (window_ == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			// create renderer for window
			renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
			if (renderer_ == NULL)
			{
				spdlog::error("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				// Initialize renderer coler
				SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG Loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					spdlog::error("SDL_Image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
				}
			}
		}
	}

	return success;
}

void Game::run()
{
	std::string tex_folder = "assets";
	Texture_Storage texture_storage{ renderer_, tex_folder };
	texture_storage.print_texture_list();
	Texture* test_texture = texture_storage.get_texture("texture1");

	bool quit = false;

	SDL_Event e;

	while (!quit)
	{

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_RenderClear(renderer_);

		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		int x = 0;
		int y = 0;

		std::cout << "Testing here" << "\n";
		std::cout << test_texture->get_filename() << "\n";
		std::cout << test_texture->get_height() << "\n";
		std::cout << test_texture->get_width() << "\n";
		test_texture->render(x, y);
		SDL_RenderPresent(renderer_);

		SDL_Delay(1000);
	}
	
}


int const Game::get_window_width()
{
	return SCREEN_WIDTH_;
}

int const Game::get_window_height()
{
	return SCREEN_HEIGHT_;
}
