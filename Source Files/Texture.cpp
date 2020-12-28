#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, std::string filename) : filename_(filename), renderer_(renderer)
{
	if (renderer == NULL){
		spdlog::error("renderer passed is null");
	}
	

	//create SDL surface
	SDL_Surface* temp_surface = IMG_Load(filename.c_str());
	if (temp_surface == NULL) {
		spdlog::error("Unable to load image : %s : %s", filename, IMG_GetError());

	}

	//Convert SDL Surface to texture
	if ((sdl_texture_ = SDL_CreateTextureFromSurface(renderer, temp_surface)) == NULL) {
		spdlog::error("Unable to create SDL texture : %s : %s", filename.c_str(), IMG_GetError());

	}

	SDL_QueryTexture(sdl_texture_, NULL, NULL, &width_, &height_);

	SDL_FreeSurface(temp_surface);

}

Texture::~Texture()
{
	if (sdl_texture_)
	{
		SDL_DestroyTexture(sdl_texture_);
		sdl_texture_ = NULL;
	}

}


int Texture::get_width()
{
	return width_;
}

int Texture::get_height()
{
	return height_;
}

std::string Texture::get_filename()
{
	return filename_;
}

void Texture::render(int x, int y)
{
	render(x, y, width_, height_);
}

void Texture::render(int x, int y, int width, int height)
{
	SDL_Rect destination{ x, y, width, height };

	SDL_RenderCopy(renderer_, sdl_texture_, NULL, &destination);
}

void Texture::render(int x, int y, int width, int height, int s_x, int s_y, int s_width, int s_height)
{
	SDL_Rect source  { s_x, s_y, s_width, s_height };
	SDL_Rect destination { x, y, width, height };

	SDL_RenderCopy(renderer_, sdl_texture_, &source, &destination);
}
