#pragma once
//#include "Manager.h"
//#include "Entity.h"
//#include "Component.h"
#include "spdlog/spdlog.h"
//#include "Physics_Component.h"
//#include "File_Manager.h"
//#include "Texture.h"
#include "Texture_Storage.h"

#include <string>
#include <iostream>

// Namespace that contians create functions
namespace Create 
{
	// These 3 functions should be called in order inside Game class constuctor.
	SDL_Window* window(int screen_width, int screen_height);
	SDL_Renderer* renderer(SDL_Window* created_window);
	std::unique_ptr<Texture_Storage> texture_storage(SDL_Renderer* created_renderer, std::string folder_path);
}
