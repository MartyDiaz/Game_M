#include "Manager.h"
#include "Entity.h"
#include "Component.h"
#include "spdlog/spdlog.h"
#include "Physics_Component.h"
#include "File_Manager.h"
#include "Texture.h"
#include "Texture_Storage.h"

#include <string>
#include <iostream>

#include "Header Files/Vector2D.h"

//***************************************************************************************************************

/*
SDL_Texture* load_texture(std::string path)
{
	//The final texture
	SDL_Texture* new_texture = NULL;

	// load image at specified path
	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == NULL)
	{
		spdlog::error("Unable to load image %s SDL_image Error: %s\n", path.c_str(), IMG_GetError());
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
*/

	//************************************************************************************************
	//SDL2 Window test
	/*
	if (!init())
	{
		printf("Failed to initialize");
	}
	else
	{
		//if (!load_media())
		//{
		//	printf("Failed to load media!\n");
		//}
		//else
		//{

		std::string tex_folder = "assets";
		Texture_Storage texture_storage{renderer, tex_folder};
		texture_storage.print_texture_list();
		Texture* test_texture = texture_storage.get_texture("texture1");

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

				//SDL_RenderCopy(renderer, texture, NULL, NULL);
				int x = 0;
				int y = 0;

				std::cout << "Testing here" << "\n";
				std::cout << test_texture->get_filename() << "\n";
				std::cout << test_texture->get_height() << "\n" ;
				std::cout << test_texture->get_width() << "\n";
				test_texture->render(x, y);
				SDL_RenderPresent(renderer);

				SDL_Delay(1000);
			}
		//}
	}
	close();
	*/

	//************************************************************************************************
	// Vector2D test
	/*
	Vector2D v1{ 0,0 };
	Vector2D v2{ 5,10 };
	Vector2D v3;
	Vector2D expected_v{ 5,10 };

	v3 = v1 + v2;

	if (v2 == v3) {
		std::cout << "Vectors are equal" << "\n";
	}
	else {
		std::cout << "Vectors are not equal" << "\n";
	}
	*/


	//**********************************************************************************************
	/*
	//Texture Storage Test
	init();
	std::string tex_folder = "assets";
	Texture_Storage texture_storage{ renderer, tex_folder };
	texture_storage.print_texture_list();
	//Texture* test_texture = texture_storage.get_texture("texture1");
	close();
	*/
	//*************************************************************************************************
	//File Manager test
	/*
	int i;

	std::vector<std::string> manager_list;

	std::string path = "assets";

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