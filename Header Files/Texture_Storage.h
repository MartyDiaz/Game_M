#pragma once

#include "Texture.h"
#include "File_Manager.h"

#include <memory>
#include <map>
#include <string>
#include <vector>

// Container that holds Texture objects.
// Owns std::map texture_list_ object that contains Textures.
// Needs a renderer passed because Texture objects need a renderer when created.
// To create a Texture_Storage call Create::texture_storage(*arguments*), this
// returns a unique ptr so caller owns Texture_Storage.
// Game class should call texture_storage_->get_texture(ID) to get a pointer
// to one of the Textures in texture_list_ , and then call ->render() on that
// pointer to draw it.
class Texture_Storage
{

private:
	std::map<std::string, std::unique_ptr<Texture>> texture_list_;
	
	// Used in the Texture_Storage contructor
	// renderer passed to create Textures. id is the key for the 
	// std::map texture_list_ containing Textures. filename is the 
	// name of the image file from which the Texture will be created.
	void add_texture(SDL_Renderer* renderer, std::string id, std::string filename);

public:
	// folder_path is path to a folder that contains image files that
	// are needed to create Textures. Texture needs the renderer being
	// passed.
	Texture_Storage(SDL_Renderer* renderer, std::string folder_path);

	Texture& get_texture(std::string ID);

	// For debugging
	void print_texture_list(); 

};