//#define SDL_MAIN_HANDLED
#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "File_Manager.h"
#include "Texture.h"
#include <string>
#include <iostream>


//*******************************************************************************************************

//SDL2 window test

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool init();

bool load_media();

void close();

SDL_Texture* load_texture(std::string path);

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

bool init()
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
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			// create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				spdlog::error("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				// Initialize renderer coler
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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

bool load_media()
{
	bool success = true;

	std::string texture_file_path = "C:\\Users\\16264\\Documents\\GitHub\\Game_M\\assets\\texture.png";

	texture = load_texture(texture_file_path);
	if (texture == NULL)
	{
		spdlog::error("Failed to load texture image\n");
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;

	//Destory window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}
//***************************************************************************************************************

SDL_Texture* load_texture(std::string path)
{
	//The final texture
	SDL_Texture* new_texture = NULL;

	// load image at specified path
	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == NULL)
	{
		spdlog::error("Unableto load image %s SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
		if (new_texture == NULL)
		{
			spdlog::error("unable to create texture form %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loaded_surface);
	}
	return new_texture;
}

int main(int argc, char* args[])
{
	//************************************************************************************************
	//SDL2 Window test
	if (!init())
	{
		printf("Failed to initialize");
	}
	else 
	{
		if (!load_media())
		{
			printf("Failed to load media!\n");
		}
		else
		{ 
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
				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, texture, NULL, NULL);

				SDL_RenderPresent(renderer);

				int x = 0;
				std::cin >> x;
			}
		}
	}
	close();
	//************************************************************************************************


	//*************************************************************************************************
	//File Manager test
	//SDL_SetMainReady();
	/*
	int i;

	std::vector<std::string> manager_list;
		
	std::string path = "";

	manager_list = File_Manager::get_files_in_folders(path, File_Manager::relative_files_opt::FILES_RELATIVE);

	for (auto x : manager_list)
	{
		std::cout << x << "\n";
	}
	
	// Testing get file_name_without_ext and get file_name_with_ext
	std::string test_string2 = "Matin.Diaz.png";
	std::string test_result2 = File_Manager::get_file_name_ext(test_string2);
	std::string test_result3 = File_Manager::get_file_name_without_ext(test_string2);
	std::cout << test_result2 << "\n";
	std::cout << test_result3 << "\n";
	std::cin >> i;
	*/
	//******************************************************************************
	

	//************************************************************************************
	// Testing spdlog 
	/*
	spdlog::info("welcome to spdlog!");
	spdlog::error("Some error message with arg: []", 1);

	spdlog::warn("Easy padding in numbers like {:08d}", 12);
	spdlog::critical("Support for int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}", 42);
	spdlog::info("Positional args are {1} {0}..", "too", "supported");
	*/
	//************************************************************************************



	//*****************************************************************************************
	// Little test of ECS system
	/*
	int i{ 0 };
	float f{ 0.0 };
	Manager test_manager;

	Entity& test_entity{ test_manager.add_entity() };

	test_entity.add_component<Physics_Component>();
	test_entity.update(f);
	test_entity.draw();

	std::cin >> i;
	*/
	//***************************************************************************************
	return 0;
}