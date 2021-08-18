#include "Game.h"


Game::Game()
{
	std::string tex_folder = "assets"; // Path to folder where Game will create 
	                                   // texture objects from image files
	
	window_ = Create::window(Constants::SCREEN_WIDTH_, Constants::SCREEN_HEIGHT_);
	renderer_ = Create::renderer(window_);
	texture_storage_ = Create::texture_storage(renderer_, tex_folder);
	
	ft_step = 0.1f; // Time step used when updating enitities 
	last_ft = 0.f; // the amount of time passed for the recent frame
	ft_slice = 0.1f; // time window
	current_slice = 0.f; // time window for the recent frame.

	Manager manager;
	auto& entity(manager.add_entity());

	entity.add_component<Counter_Component>(0.0);
	entity.add_component<Kill_Component>(&entity.get_component<Counter_Component>());


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
	//Texture* test_texture = texture_storage_.get()->get_texture("texture1"); 
	//I don't think I need the .get() above 
	
	//Texture& test_texture = texture_storage_->get_texture("texture1");
	
	bool quit = false;

	//SDL_Event e;

	while (!quit)
	{
		auto time_point_1(std::chrono::high_resolution_clock::now());
		input_phase();
		update_phase();
		draw_phase();
		auto time_point_2(std::chrono::high_resolution_clock::now());
		auto elapsed_time(time_point_2 - time_point_1);

		float frame_time{ 
			std::chrono::duration_cast<std::chrono::duration<float, std::milli>>
				(elapsed_time).count() 
		};

		last_ft = frame_time;

		auto frame_time_seconds(frame_time / 1000.f);
		auto fps(1.f / frame_time_seconds);

		//std::cout << "Frame time: " + std::to_string(frame_time) + "\tFPS: " + std::to_string(fps) + "\n";

	}
	
}

void Game::input_phase()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}

void Game::update_phase()
{
	current_slice += last_ft;
	for (; current_slice >= ft_slice; current_slice -= ft_slice)
	{
		// std::cout << "Updating\n";
	}

}

void Game::draw_phase()
{
	Texture& test_texture = texture_storage_->get_texture("texture1");
	SDL_RenderClear(renderer_);

	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	int x = 0;
	int y = 0;

	std::cout << "Testing here" << "\n";
	std::cout << test_texture.get_filename() << "\n";
	std::cout << test_texture.get_height() << "\n";
	std::cout << test_texture.get_width() << "\n";
	test_texture.render(x, y);
	SDL_RenderPresent(renderer_);
}


int const Game::get_window_width()
{
	return Constants::SCREEN_WIDTH_;
}

int const Game::get_window_height()
{
	return Constants::SCREEN_HEIGHT_;
}
