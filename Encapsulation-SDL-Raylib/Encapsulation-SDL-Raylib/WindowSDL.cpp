#include "WindowSDL.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "SpriteSDL.h"

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
	const int supportedFormats = IMG_INIT_PNG | IMG_INIT_JPG;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Error Initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		exit(1);
	}

	if (!(IMG_Init(supportedFormats) & supportedFormats))
	{
		std::cerr << "Error Initializing SDL_image : " << IMG_GetError() << std::endl;
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
	if (!mWindowSurface) return;

	SDL_Rect targetPosition;
	targetPosition.x = static_cast<int>(Entity->GetPosition().x);
	targetPosition.y = static_cast<int>(Entity->GetPosition().y);

	SpriteSDL* sdlSprite = dynamic_cast<SpriteSDL*>(Entity->GetSprite());
	int drawResult = SDL_BlitSurface(sdlSprite->GetImage(), NULL, mWindowSurface, &targetPosition);
}

void WindowSDL::BeginDraw()
{
}

void WindowSDL::EndDraw()
{
	if (!mWindow || !mWindowSurface) return;

	SDL_UpdateWindowSurface(mWindow);
}

void WindowSDL::DestroyWindow()
{
	if (!mWindow) return;
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	mWindowSurface = nullptr;

	SDL_Quit();
	IMG_Quit();
}


