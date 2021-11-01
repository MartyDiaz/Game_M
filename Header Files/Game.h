#ifndef Game_H
#define Game_H

#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "Counter_Component.h"
#include "Kill_Component.h"
#include "Transform_Component.h"
#include "Graphic_Component.h"
#include "Move_Component.h"
#include "File_Manager.h"
#include "Texture.h"
#include "Texture_Storage.h"
#include "Create.h"
#include "Constants.h"
#include "Move_Command.h"
#include "Input_Handler.h"

#include <chrono>
#include <string>
#include <iostream>
// Game runs the game loop.
// Constructor creates window and renderer for the game. Also creates 
// texure_storage object to hold textures. Game object owns window_ 
// and renderer_ raw pointers, they are destroyed in the destructor. 
// Game also owns texture_storage_ and is a unique pointer.
// Only one instance of Game should be made.
class Game
{
private:

	bool quit_ = false;

	//inline constexpr int SCREEN_HEIGHT_ = 480;
	//inline constexpr int SCREEN_WIDTH_ = 640;

	std::unique_ptr<Texture_Storage> texture_storage_;
	
	SDL_Window* window_ = NULL;
	SDL_Renderer* renderer_ = NULL;
	Move_Command* movement_command_ = NULL;

	Input_Handler input_handler_;

	SDL_Event event_;

	SDL_Rect camera_;

	Manager manager_;

	Entity* player_entity;

	enum entity_groups : std::size_t
	{
		move_command_group
	};


public:
	Game(int screen_width, int screen_height);
	~Game();

	//bool init_window();
	//void init_texture_storage();
	float ft_step;
	float ft_slice;
	float last_ft;
	float current_slice;

	void run();
	
	void input_phase();

	void update_phase();

	void draw_phase();

	void movement_input();

	void camera_update();

	int const get_window_width();

	int const get_window_height();

};
#endif
