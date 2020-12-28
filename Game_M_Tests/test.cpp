//#include "pch.h"
//#define SDL_MAIN_HANDLED
#include "Header Files/File_Manager.h"
#include "Header Files/Manager.h"
#include "Header Files/Entity.h"
#include "Header Files/Texture_Storage.h"

#include "gtest/gtest.h"


TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(File_Manager, get_CWD)
{
	std::string expected = "C:\\Users\\16264\\Documents\\GitHub\\Game_M\\x64\\Debug";
	std::string CWD = File_Manager::get_current_working_directory();
	ASSERT_EQ(expected, CWD);
}


// Testing get files in folder
TEST(File_Manager, get_files_non_relative)
{
	std::vector<std::string> manager_list;
	std::vector<std::string> test_list;
	std::string path = "C:\\Users\\16264\\Documents\\GitHub\\Game_M\\temp test";

	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\temp test\\Test1.txt");
	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\temp test\\Test2.txt");
	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\temp test\\Test3.txt");


	manager_list = File_Manager::get_files_in_folders(path, File_Manager::relative_files_opt::FILES_NOT_RELATIVE);
	
	ASSERT_EQ(test_list.size(), manager_list.size()) << "Vectors x and y are not equal size";
	
	for (int i = 0; i < test_list.size(); i++)
	{
		EXPECT_EQ(test_list[i], manager_list[i]);
	}
}

TEST(File_Manager, get_files_relative)
{
	std::vector<std::string> manager_list;
	std::vector<std::string> test_list;

	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test1.txt");
	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test2.txt");
	test_list.emplace_back("C:\\Users\\16264\\Documents\\GitHub\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test3.txt");

	std::string path = "..\\..\\temp test";

	manager_list = File_Manager::get_files_in_folders(path, File_Manager::relative_files_opt::FILES_RELATIVE);

	std::cout << "Testing 1 2 3" << "\n";

	ASSERT_EQ(test_list.size(), manager_list.size()) << "Vectors x and y are not equal size";

	for (int i = 0; i < test_list.size(); i++)
	{
		EXPECT_EQ(test_list[i], manager_list[i]);
	}

}












