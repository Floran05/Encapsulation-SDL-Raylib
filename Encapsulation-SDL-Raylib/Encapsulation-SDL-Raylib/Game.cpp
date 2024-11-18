#include "Game.h"

#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"


#include "EntitySDL.h"

Game::Game()
	: mSelectedLibrary(ELibrary::SDL)
	, mWindow(nullptr)
{
}

void Game::Init(const ELibrary& Library)
{
	mSelectedLibrary = Library;

	switch (mSelectedLibrary)
	{
	case ELibrary::SDL:
		mWindow = new WindowSDL();
		break;
	case ELibrary::Raylib:
		mWindow = new WindowRaylib();
		break;
	default:
		std::cerr << "Bad library selected. Exiting..." << std::endl;
		system("pause");
		exit(1);
		break;
	}

	mWindow->InitLibrary();
	mWindow->CreateWindow("Encapsulation - SDL - Raylib", 1080, 720);
}

void Game::Loop()
{
}
