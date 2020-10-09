#include "Test.h"
#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "Physics_Component.h"


#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <iostream>




int main(int argc, char* args[])
{
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