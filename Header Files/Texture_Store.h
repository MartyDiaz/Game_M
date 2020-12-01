#pragma once

#include <SDL.h>

#include <memory>
#include <map>
#include <string>
#include <vector>


class Texture_Store
{

private:
	std::map<std::string, std::unique_ptr<SDL_Texture*>> texture_list;

	void add_texture(std::string id, const char* path);
public:
	SDL_Texture* get_texture(std::string ID);

};