#include "Test.h"
#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "File_Manager.h"

#include <string>
#include <iostream>


int main(int argc, char* args[])
{
	//*******************************************************************************
	
	int i;
	
	// Testing get file_name_without_ext and get file_name_with_ext
	std::string test_string2 = "Matin.Diaz.png";
	std::string test_result2 = File_Manager::get_file_name_ext(test_string2);
	std::string test_result3 = File_Manager::get_file_name_without_ext(test_string2);
	std::cout << test_result2 << "\n";
	std::cout << test_result3 << "\n";
	std::cin >> i;

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
	


	//*******************************************************************************************
	/*
	//SDL2 window test
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);

			SDL_Delay(2000);
			 }
	}


		SDL_DestroyWindow;
		SDL_Quit();
		*/
	//**************************************************************************************

	//SDL_Window* Window = NULL;
	//SDL_Renderer* Renderer = NULL;
	//SDL_Surface* PrimarySurface = NULL;
	//const int SCREEN_WIDTH = 640;
	//const int SCREEN_HEIGHT = 480;
	
	return 0;
}