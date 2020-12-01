#include "FileManager.h"
 
/*
bool FileManager::set_contents(std::string file_name, std::string content, bool relative)
{
	if (file_name == "") return false;

	if (relative) file_name = get_CWD() + DIR_SEPERATOR + file_name;

	std::ofstream file_handle;

	file_handle.open(file_name.c_str());
	if (!file_handle.is_open()) return false;

	file_handle << content;
	file_handle.close();

	return true;
}
*/

/*
std::string FileManager::get_contents(std::string file_name, bool relative)
{
	if (file_name == "") return "";

	if (relative) file_name = get_current_working_directory() + dir_seperator + file_name;

	std::string content;
	std::ifstream file_handle;

	file_handle.open(file_name.c_str());

	if (file_handle.is_open())
	{
		while (file_handle.good())
		{
			std::string buffer;
			getline(file_handle, buffer);
			if (buffer == "") continue;

			content += buffer + "\n";
		}

		file_handle.close();
	}

	return content;
}
*/

std::vector<std::string> FileManager::get_files_in_folders(std::string folder)
{
	std::vector<std::string> list;

	std::string current_working_directory = get_current_working_directory();
	std::string path = current_working_directory;
 
	path += dir_seperator + folder;
	//directory_iterator constructor throws error if path is wrong.
	//How to handle this?

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

std::string FileManager::get_current_working_directory()
{
	std::string current_working_diectory = std::filesystem::current_path().string() ;
	return current_working_diectory;
}

std::string FileManager::get_file_name_without_ext(std::string filename)
{
	// Possible to use filesystem functions to implement this method. I think you
	// create a filesystem::path with a string then use remove ext function then
	// convert back to a string. Probably is safer but not sure if performance will 
	// be slow. So using boost split for now.
	std::vector<std::string> result;

	boost::split(result, filename, boost::is_any_of("."));

	return result[result.size() - 2];
}

std::string FileManager::get_file_name_ext(std::string filename)
{
	// Possible to use filesystem functions to implement this method. I think you
	// create a filesystem::path with a string then use remove ext function then
	// convert back to a string. Probably is safer but not sure if performance will 
	// be slow. So using boost split for now.
	std::vector<std::string> result;

	boost::split(result, filename, boost::is_any_of("."));

	return result.back();
}