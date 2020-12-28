#pragma once

#include <SDL.h>
#include "Texture.h"
#include "File_Manager.h"

#include <memory>
#include <map>
#include <string>
#include <vector>


class Texture_Storage
{

private:
	std::map<std::string, std::unique_ptr<Texture>> texture_list_;

	void add_texture(SDL_Renderer* renderer, std::string id, std::string filename);

public:

	Texture_Storage(SDL_Renderer* renderer, std::string folder_path);

	Texture* get_texture(std::string ID);

	void print_texture_list();

};