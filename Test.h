#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Test
{
private:
	// Capture SDL Events
	void OnEvent(SDL_Event* Event);

	// Initialize our SDL game / app
	bool Init();

	// Logic loop
	void Loop();

	// Render loop (Draw)

	void Render();

	// Free up resources
	void Cleanup();

public:

	int GetWindowWidth();

	int GetWindowHeight();

};

