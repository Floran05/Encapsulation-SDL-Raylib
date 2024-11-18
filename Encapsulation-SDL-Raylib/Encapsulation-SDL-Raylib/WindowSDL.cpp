#include "WindowSDL.h"

#include <iostream>
#include <SDL2/SDL.h>

#include "Entity.h"

WindowSDL::WindowSDL()
	: mWindowSurface(nullptr)
	, mWindow(nullptr)
{
}

WindowSDL::~WindowSDL()
{
	delete mWindowSurface;
	delete mWindow;
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
	mWindow = SDL_CreateWindow(
		WindowTitle.c_str(), 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		Width, 
		Height, 
		SDL_WINDOW_SHOWN
	);

	if (!mWindow)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		system("pause");
		exit(1);
	}

	mWindowSurface = SDL_GetWindowSurface(mWindow);
	
	if (!mWindowSurface)
	{
		std::cerr << "Error getting surface: " << SDL_GetError() << std::endl;
		system("pause");
		exit(1);
	}
}

void WindowSDL::DrawEntity(Entity* Entity)
{

}

void WindowSDL::BeginDraw()
{
}

void WindowSDL::EndDraw()
{
}

void WindowSDL::DestroyWindow()
{
	if (!mWindow) return;
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	mWindowSurface = nullptr;
}


