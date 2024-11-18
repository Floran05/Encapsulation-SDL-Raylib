#include "WindowSDL.h"

#include <iostream>
#include <SDL2/SDL.h>

WindowSDL::WindowSDL()
{
}

WindowSDL::~WindowSDL()
{
}

void WindowSDL::InitLibrary()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Error Initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		exit(1);
	}
}

void WindowSDL::CreateWindow(const std::string& WindowTitle, int Width, int Height)
{
}


