#include "Texture_Storage.h"

Texture_Storage::Texture_Storage(SDL_Renderer* renderer, std::string folder_path)
{
	using f_option = File_Manager::relative_files_opt;
	std::vector<std::string> file_list = File_Manager::get_files_in_folders(folder_path, f_option::FILES_RELATIVE);

	for (auto filename : file_list)
	{
		std::string ext = File_Manager::get_file_name_ext(filename);
		std::string id = File_Manager::get_file_name_without_ext(filename);

		add_texture(renderer, id, filename);

	}

}

void Texture_Storage::add_texture(SDL_Renderer* renderer, std::string id, std::string filename)
{

	texture_list_.emplace(id, std::make_unique<Texture>(Texture{renderer,filename}));
}


Texture* Texture_Storage::get_texture(std::string id)
{
	return texture_list_.at(id).get();
}
