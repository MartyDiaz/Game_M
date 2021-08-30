#include "Header Files/Game.h"
//#define SDL_MAIN_HANDLED
//*******************************************************************************************************

//***************************************************************************************************************
int main(int argc, char* args[])
{
	Game testgame{Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT };
	testgame.run();

	return 0;
}