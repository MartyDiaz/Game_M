#include "Game.h"


Game::Game()
{
	std::string tex_folder = "assets";
	window_ = Create::window(Constants::SCREEN_WIDTH_, Constants::SCREEN_HEIGHT_);
	renderer_ = Create::renderer(window_);
	texture_storage_ = Create::texture_storage(renderer_, tex_folder);
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


void Game::run()
{
	texture_storage_.get()->print_texture_list();
	Texture* test_texture = texture_storage_.get()->get_texture("texture1");

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
	return Constants::SCREEN_WIDTH_;
}

int const Game::get_window_height()
{
	return Constants::SCREEN_HEIGHT_;
}
