#include "File_Manager.h"
 
std::string File_Manager::dir_seperator = "\\";

//Enums
//FILES_RELATIVE,
//FILES_NOT_RELATIVE

//TODO: This function is hard to read. Mabye boost has something similar that can replace this.
std::vector<std::string> File_Manager::get_files_in_folders(std::string folder, relative_files_opt rel)
{
	std::vector<std::string> list;
	std::error_code errc;

	std::string current_working_directory = get_current_working_directory();
	std::string path = "";
	if (rel == relative_files_opt::FILES_RELATIVE)
	{
		path += current_working_directory + File_Manager::dir_seperator + folder;
	}
	else if (rel == relative_files_opt::FILES_NOT_RELATIVE) {
		path += folder;
	}

	// std::error should handle errors with path
	using directory_iterator = std::filesystem::directory_iterator;
	directory_iterator path_iterator = directory_iterator(path, errc);
	if (not errc)
	{ 
		for (const auto& file : path_iterator)
		{
			list.emplace_back(file.path().string());
		}	
	} else 
	{
			spdlog::error(errc.message());
	}
	return list;	
}


std::string File_Manager::get_current_working_directory()
{
	std::string current_working_diectory = std::filesystem::current_path().string() ;
	return current_working_diectory;
}

std::string File_Manager::get_file_name_without_ext(std::string filename)
{
	// Possible to use filesystem functions to implement this method. I think you
	// create a filesystem::path with a string then use remove ext function then
	// convert back to a string. Probably is safer but not sure if performance will 
	// be slow. So using boost split for now.
	std::vector<std::string> directory_parts;
	boost::split(directory_parts, filename, boost::is_any_of("\\"));
	std::string result = directory_parts.back();

	std::vector<std::string> ext_part;
	boost::split(ext_part, result, boost::is_any_of("."));
	return ext_part[ext_part.size() - 2];
}

std::string File_Manager::get_file_name_ext(std::string filename)
{
	// Possible to use filesystem functions to implement this method. I think you
	// create a filesystem::path with a string then use remove ext function then
	// convert back to a string. Probably is safer but not sure if performance will 
	// be slow. So using boost split for now.
	std::vector<std::string> result;
	boost::split(result, filename, boost::is_any_of("."));
	return result.back();
}