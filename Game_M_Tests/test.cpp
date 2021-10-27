//#include "pch.h"
//#define SDL_MAIN_HANDLED
#include "Header Files/File_Manager.h"
#include "Header Files/Manager.h"
#include "Header Files/Entity.h"
#include "gtest/gtest.h"
#include "Header Files/Vector2D.h"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(FileManager, getCWD)
{
	std::string expected = "C:\\Users\\marty\\source\\repos\\Game_M\\x64\\Debug";
	std::string CWD = File_Manager::get_current_working_directory();
	ASSERT_EQ(expected, CWD);
}


// Testing get files in folder
TEST(FileManager, getFilesNonRelative)
{
	std::vector<std::string> manager_list;
	std::vector<std::string> test_list;
	std::string path = "C:\\Users\\marty\\source\\repos\\Game_M\\temp test";

	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\temp test\\Test1.txt");
	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\temp test\\Test2.txt");
	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\temp test\\Test3.txt");


	manager_list = File_Manager::get_files_in_folders(path, File_Manager::relative_files_opt::FILES_NOT_RELATIVE);
	
	ASSERT_EQ(test_list.size(), manager_list.size()) << "Vectors x and y are not equal size";
	
	for (int i = 0; i < test_list.size(); i++)
	{
		EXPECT_EQ(test_list[i], manager_list[i]);
	}
}

TEST(FileManager, getFilesRelative)
{
	std::vector<std::string> manager_list;
	std::vector<std::string> test_list;

	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test1.txt");
	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test2.txt");
	test_list.emplace_back("C:\\Users\\marty\\source\\repos\\Game_M\\x64\\Debug\\..\\..\\temp test\\Test3.txt");

	std::string path = "..\\..\\temp test";

	manager_list = File_Manager::get_files_in_folders(path, File_Manager::relative_files_opt::FILES_RELATIVE);

	std::cout << "Testing 1 2 3" << "\n";

	ASSERT_EQ(test_list.size(), manager_list.size()) << "Vectors x and y are not equal size";

	for (int i = 0; i < test_list.size(); i++)
	{
		EXPECT_EQ(test_list[i], manager_list[i]);
	}

}

TEST(Vector2DTests, addition)
{
	Vector2D v1{ 0,0 };
	Vector2D v2{ 5,10 };
	Vector2D v3;
	Vector2D expected_v{ 5,10 };

	v3 = v1 + v2;

	EXPECT_EQ(v3, expected_v);
}

TEST(Vector2DTests, substraction)
{
	Vector2D v1{ 10,10 };
	Vector2D v2{ 5,10 };
	Vector2D v3;
	Vector2D expected_v{ 5,0 };

	v3 = v1 - v2;

	EXPECT_EQ(v3, expected_v);
}

TEST(Vector2DTests, additionEquals)
{
	Vector2D v1{ 2,2 };
	Vector2D v2{ 5,10 };

	Vector2D expected_v{ 7,12 };
	v1 += v2;

	EXPECT_EQ(v1, expected_v);
}

TEST(Vector2DTests, subtractionEquals)
{
	Vector2D v1{ 10,10 };
	Vector2D v2{ 2,2 };

	Vector2D expected_v{ 8,8 };
	v1 -= v2;

	EXPECT_EQ(v1, expected_v);
}












