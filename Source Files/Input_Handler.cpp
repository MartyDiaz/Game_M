#include "Input_Handler.h"

Input_Handler::Input_Handler() : move_command_{ std::make_unique<Move_Command>() }
{

}

Move_Command* Input_Handler::handle_move_input(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			move_command_.get()->direction_.y_ = -1;
			spdlog::info("Keydown w.");
			return move_command_.get();
			break;
		case SDLK_a:
			move_command_.get()->direction_.x_ = -1;
			spdlog::info("Keydown a.");
			return move_command_.get();
			break;
		case SDLK_d:
			move_command_.get()->direction_.x_ = 1;
			spdlog::info("Keydown d.");
			return move_command_.get();
			break;
		case SDLK_s:
			move_command_.get()->direction_.y_ = 1;
			spdlog::info("Keydown s.");
			return move_command_.get();
			break;
		}
	}
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			move_command_.get()->direction_.y_ = 1;
			spdlog::info("Keyup w.");
			return move_command_.get();
			break;
		case SDLK_a:
			move_command_.get()->direction_.x_ = 1;
			spdlog::info("Keyup a.");
			return move_command_.get();
			break;
		case SDLK_d:
			move_command_.get()->direction_.x_ = -1;
			spdlog::info("Keyup d.");
			return move_command_.get();
			break;
		case SDLK_s:
			move_command_.get()->direction_.y_ = -1;
			spdlog::info("Keyup s.");
			return move_command_.get();
			break;
		}
	}
	move_command_.get()->direction_.zero();
	return move_command_.get();
}