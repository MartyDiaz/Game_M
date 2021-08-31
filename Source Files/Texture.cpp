#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, std::string filename) : renderer_(renderer), filename_(filename)
{
	if (renderer_ == NULL){
		spdlog::error("renderer passed is null");
	}
	

	//create SDL surface
	SDL_Surface* temp_surface = IMG_Load(filename_.c_str());
	spdlog::error(IMG_GetError());
	spdlog::error(SDL_GetError());
	if (temp_surface == NULL) {
		spdlog::error("Unable to load image : %s : %s", filename_, IMG_GetError());

	}

	//Convert SDL Surface to texture
	sdl_texture_ = SDL_CreateTextureFromSurface(renderer_, temp_surface);
	if (sdl_texture_ == NULL)
	{
		spdlog::error("Unable to create SDL texture : %s : %s", filename_.c_str(), IMG_GetError());
	}
	
	// width_ and height_ are obtained from the dimensions of the image file.
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


int Texture::get_width() const
{
	return width_;
}

int Texture::get_height() const
{
	return height_;
}

std::string Texture::get_filename() const
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
	//spdlog::error ( "Rect width is ");
	//spdlog::error( "Rect height is ");
	SDL_RenderCopy(renderer_, sdl_texture_, NULL, &destination);
}

void Texture::render(int x, int y, int width, int height, int s_x, int s_y, int s_width, int s_height)
{
	SDL_Rect source  { s_x, s_y, s_width, s_height };
	SDL_Rect destination { x, y, width, height };

	SDL_RenderCopy(renderer_, sdl_texture_, &source, &destination);
}

void Texture::render(SDL_Rect source, SDL_Rect destination)
{
	SDL_RenderCopy(renderer_, sdl_texture_, &source, &destination);
}
