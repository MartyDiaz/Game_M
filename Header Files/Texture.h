#pragma once
//#define SDL_MAIN_HANDLED
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include "spdlog/spdlog.h"

class Texture
{
private:
	std::string filename_;
	SDL_Texture* sdl_texture_ = NULL;

	int width_ = 0;
	int height_ = 0;

public:
	Texture(SDL_Renderer* renderer, std::string filename);

	~Texture();

	int get_width();
	int get_height();

};