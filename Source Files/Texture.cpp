#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, std::string filename) : filename_(filename)
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
