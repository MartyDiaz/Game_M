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
	SDL_Renderer* renderer_;

	int width_ = 0;
	int height_ = 0;

public:
	Texture(SDL_Renderer* renderer, std::string filename);

	~Texture();

	int get_width();
	int get_height();
	std::string get_filename();

	void render(int x, int y);

	void render(int x, int y, int width, int height);

	void render(int x, int y, int width, int height, int s_x, int s_y, int s_width, int s_height);

};