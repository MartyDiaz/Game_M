#pragma once

#include "Move_Command.h"
#include "SDL.h"

class Input_Handler
{

public:
	std::unique_ptr<Move_Command> move_command_;
	
	Input_Handler();

	Move_Command* handle_move_input(SDL_Event& event);

};