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


class FileManager 
{
private:
	std::string dir_seperator = "/";
	std::error_code errc;
public:

	//static bool set_contents(std::string Filename, std::string Content, bool Relative = true);

	std::string get_contents(std::string filename, bool relative = true);

	std::vector<std::string> get_files_in_folders(std::string folder);

	std::string get_current_working_directory();

	std::string get_file_name_without_ext(std::string filename);

	std::string get_file_name_ext(std::string filename);

};

