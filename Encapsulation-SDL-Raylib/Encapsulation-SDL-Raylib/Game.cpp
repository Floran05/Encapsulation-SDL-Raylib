#include "Game.h"

#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

Game::Game(const ELibrary& Library)
	: mSelectedLibrary(ELibrary::SDL)
	, mWindow(nullptr)
{
}

void Game::Init()
{
	switch (mSelectedLibrary)
	{
	case ELibrary::SDL:
		mWindow = new WindowSDL();
		break;
	case ELibrary::Raylib:
		// mWindow = new WindowRaylib();
		break;
	default:
		std::cerr << "Bad library selected. Exiting..." << std::endl;
		system("pause");
		exit(1);
		break;
	}


}
