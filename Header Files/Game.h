#ifndef Game_H
#define Game_H

#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "Counter_Component.h"
#include "Kill_Component.h"
#include "File_Manager.h"
#include "Texture.h"
#include "Texture_Storage.h"
#include "Create.h"
#include "Constants.h"

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

	bool quit = false;

	//inline constexpr int SCREEN_HEIGHT_ = 480;
	//inline constexpr int SCREEN_WIDTH_ = 640;

	std::unique_ptr<Texture_Storage> texture_storage_;
	
	SDL_Window* window_ = NULL;
	SDL_Renderer* renderer_ = NULL;


public:
	Game();
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

	int const get_window_width();

	int const get_window_height();

};
#endif
