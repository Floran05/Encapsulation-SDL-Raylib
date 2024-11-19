#include "Game.h"

#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"
#include "TimeManagerSDL.h"
#include "TimeManagerRaylib.h"
#include "EntitySDL.h"
#include "EntityRaylib.h"
#include "ControllerSDL.h"
#include "ControllerRaylib.h"

Game::Game()
	: mSelectedLibrary(ELibrary::SDL)
	, mWindow(nullptr)
	, mController(nullptr)
{
}

void Game::Init(const ELibrary& Library, const std::string& WindowTitle, int WindowWidth, int WindowHeight, int MaxFramerate)
{
	mSelectedLibrary = Library;

	switch (mSelectedLibrary)
	{
	case ELibrary::SDL:
		mWindow = new WindowSDL();
		mTimeManager = new TimeManagerSDL();
		mController = new ControllerSDL();
		mE = new EntitySDL();
		break;
	case ELibrary::Raylib:
		mWindow = new WindowRaylib();
		mTimeManager = new TimeManagerRaylib();
		//mController = new ControllerRaylib();
		mE = new EntityRaylib();
		break;
	default:
		std::cerr << "Bad library selected. Exiting..." << std::endl;
		system("pause");
		exit(1);
		break;
	}

	mWindow->InitLibrary();
	mWindow->CreateWindow(WindowTitle, WindowWidth, WindowHeight);

	mTimeManager->SetMaxFramerate(MaxFramerate);

	mE->Init("C:\\Users\\fcarvalho\\Pictures\\sample_PNG.png");
}

void Game::Loop()
{
	while (mWindow->IsWindowOpen())
	{
		mTimeManager->OnFrameStart();
		mWindow->ProcessEvents();

		mWindow->BeginDraw();
		// update balls
		// update player
		mWindow->DrawEntity(mE);
		// draw
		// draw fps
		mWindow->EndDraw();

		mTimeManager->GetElapsedTime();
		mTimeManager->ApplyFramerateLimit();
	}

	mWindow->DestroyWindow();
}