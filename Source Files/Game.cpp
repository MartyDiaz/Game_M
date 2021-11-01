#include "Game.h"

Game::Game(int screen_width, int screen_height) : camera_{ 0, 0, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT }
{
	std::string tex_folder = "assets"; // Path to folder where Game will create 
	                                   // texture objects from image files
	
	window_ = Create::window(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
	renderer_ = Create::renderer(window_);
	texture_storage_ = Create::texture_storage(renderer_, tex_folder); //Unique Pointer

	ft_step = 1.f; // Time step used when updating enitities 
	last_ft = 0.f; // the amount of time passed for the recent frame
	ft_slice = 1.f; // time window
	current_slice = 0.f; // time window for the recent frame.

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
	//texture_storage_.get()->print_texture_list();
	//Texture* test_texture = texture_storage_.get()->get_texture("texture1"); 
	//I don't think I need the .get() above 
	
	//Texture& test_texture = texture_storage_->get_texture("texture1");
	
	bool quit = false;

	//Makeing test entity
	auto& back_entity(manager_.add_entity());
	auto& test_entity(manager_.add_entity());

	// back ground picture
	back_entity.add_component<Transform_Component>(0, 0);
	back_entity.add_component<Graphic_Component>(&back_entity.get_component<Transform_Component>(), texture_storage_.get(), "space", camera_);

	//player enitity
	test_entity.add_component<Transform_Component>(1000.0, 750.0);
	test_entity.add_component<Graphic_Component>(&test_entity.get_component<Transform_Component>(), texture_storage_.get(), "ship3", camera_);
	test_entity.add_component<Move_Component>(&test_entity.get_component<Transform_Component>());
	test_entity.add_group(entity_groups::move_command_group);
	player_entity = &test_entity;

	



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
	while (SDL_PollEvent(&event_) != 0)
	{
		if (event_.type == SDL_QUIT)
		{
			quit_ = true;
		}
		movement_input();
	}
}

void Game::update_phase()
{
	current_slice += last_ft;
	for (; current_slice >= ft_slice; current_slice -= ft_slice)
	{
		manager_.refresh();
		manager_.update(ft_step);
	}
	camera_update();
}

void Game::draw_phase()
{
//	Texture* test_texture = texture_storage_->get_texture("texture1");
	SDL_RenderClear(renderer_);

	//SDL_RenderCopy(renderer, texture, NULL, NULL);
//	int x = 0;
//	int y = 0;
	manager_.draw();
//	std::cout << "Testing here" << "\n";
//	std::cout << test_texture->get_filename() << "\n";
//	std::cout << test_texture->get_height() << "\n";
//	std::cout << test_texture->get_width() << "\n";
//	test_texture->render(x, y);
	SDL_RenderPresent(renderer_);
}


int const Game::get_window_width()
{
	return Constants::SCREEN_WIDTH;
}

int const Game::get_window_height()
{
	return Constants::SCREEN_HEIGHT;
}

void Game::movement_input()
{
	movement_command_ = input_handler_.handle_move_input(event_);

	if (movement_command_->not_zero())
	{
		auto& entities_to_move(manager_.get_entities_by_group(move_command_group));

		for (auto& entity : entities_to_move)
		{
			movement_command_->execute(*entity);
		}
		movement_command_->zero();
	}
}

void Game::camera_update()
{
	camera_.x = player_entity->get_component<Transform_Component>()
		.position_.x_ - Constants::SCREEN_WIDTH/2;
	
	camera_.y = player_entity->get_component<Transform_Component>()
		.position_.y_ - Constants::SCREEN_HEIGHT/2;

	if (camera_.x < 0)
	{
		camera_.x = 0;
	}
	if (camera_.y < 0)
	{
		camera_.y = 0;
	}
	if (camera_.x > camera_.w)
	{
		camera_.x = camera_.w;
	}
	if (camera_.y > camera_.h)
	{
		camera_.y = camera_.h;
	}
}