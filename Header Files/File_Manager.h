#pragma once

#include "spdlog/spdlog.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <Windows.h>
#include <stdio.h>
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <system_error>


namespace File_Manager 
{
	enum class relative_files
	{
		FILES_RELATIVE, 
		FILES_NOT_RELATIVE
	};

	extern std::string dir_seperator;
	
	std::vector<std::string> get_files_in_folders(std::string folder, relative_files );

	std::string get_current_working_directory();

	std::string get_file_name_without_ext(std::string filename);

	std::string get_file_name_ext(std::string filename);

};

