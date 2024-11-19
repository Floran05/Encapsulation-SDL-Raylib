#include "Game.h"

#include <iostream>
#include <string>  
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
	, mTimeManager(nullptr)
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
		mController = new ControllerRaylib();
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

	mE->Init("C:\\Users\\L3iith\\Desktop\\ball.png");
}

void Game::Loop()
{
	while (mWindow->IsWindowOpen())
	{
		mTimeManager->OnFrameStart();
		mWindow->ProcessEvents();

		mWindow->BeginDraw();

		mWindow->DrawEntity(mE);
		mWindow->DrawText(std::to_string(static_cast<int>(round(1 / mTimeManager->GetElapsedTime())))+" FPS", 980, 50, 20);
		
		mWindow->EndDraw();

		mTimeManager->ApplyFramerateLimit();
	}

	mWindow->DestroyWindow();
}