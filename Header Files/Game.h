#ifndef Game_H
#define Game_H

#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "File_Manager.h"
#include "Texture.h"
#include "Texture_Storage.h"
#include "Create.h"
#include "Constants.h"

#include <string>
#include <iostream>
class Game
{
private:

	bool Running = true;

	//inline constexpr int SCREEN_HEIGHT_ = 480;
	//inline constexpr int SCREEN_WIDTH_ = 640;

	std::unique_ptr<Texture_Storage> texture_storage_;
	
	SDL_Window* window_ = NULL;
	SDL_Renderer* renderer_ = NULL;

public:
	Game();
	~Game();

	bool init_window();
	//void init_texture_storage();

	void run();

	int const get_window_width();

	int const get_window_height();

};
#endif
