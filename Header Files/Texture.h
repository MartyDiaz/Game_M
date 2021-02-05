#pragma once
//#define SDL_MAIN_HANDLED
#include <string>
#include "spdlog/spdlog.h"
#include "SDL.h"
#include "SDL_image.h"

class Texture
{
private:
	std::string filename_;
	SDL_Texture* sdl_texture_ ;
	SDL_Renderer* renderer_ ;

	int width_;
	int height_;

public:
	Texture(SDL_Renderer* renderer, std::string filename);

	Texture(const Texture* other) = delete;
	Texture(Texture&& other) = delete;
	Texture& operator=(const Texture& other) = delete;
	Texture& operator=(Texture&& other) = delete;

	~Texture();

	int get_width();
	int get_height();
	std::string get_filename();

	void render(int x, int y);

	void render(int x, int y, int width, int height);

	void render(int x, int y, int width, int height, int s_x, int s_y, int s_width, int s_height);

};