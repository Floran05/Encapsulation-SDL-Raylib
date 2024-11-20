#include "Game.h"

#include <iostream>
#include <string>  
#include "WindowSDL.h"
#include "WindowRaylib.h"
#include "TimeManagerSDL.h"
#include "TimeManagerRaylib.h"
#include "ControllerSDL.h"
#include "ControllerRaylib.h"
#include "Player.h"
#include "Ball.h"
#include "Sprite.h"

Game::Game()
	: mSelectedLibrary(ELibrary::SDL)
	, mWindow(nullptr)
	, mController(nullptr)
	, mTimeManager(nullptr)
	, mPlayerLeft(nullptr)
	, mPlayerRight(nullptr)
	, mBall(nullptr)
{
}

void Game::Init(const ELibrary& Library, const std::string& WindowTitle, int WindowWidth, int WindowHeight, int MaxFramerate)
{
	mSelectedLibrary = Library;

	mPlayerLeft = new Player();
	mPlayerRight = new Player();
	mBall = new Ball();
	switch (mSelectedLibrary)
	{
	case ELibrary::SDL:
		mWindow = new WindowSDL();
		mTimeManager = new TimeManagerSDL();
		mController = new ControllerSDL();
		mPlayerLeft->SetControlKeys(SDLK_z, SDLK_s);
		mPlayerRight->SetControlKeys(SDLK_UP, SDLK_DOWN);
		break;
	case ELibrary::Raylib:
		mWindow = new WindowRaylib();
		mTimeManager = new TimeManagerRaylib();
		mController = new ControllerRaylib();
		mPlayerLeft->SetControlKeys(KEY_Z, KEY_S);
		mPlayerRight->SetControlKeys(KEY_UP, KEY_DOWN);
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

	Sprite* playerLeftSprite = mWindow->CreateSprite("C:\\Users\\carva\\Documents\\GTech\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Resources\\Computer.png");
	Sprite* playerRightSprite = mWindow->CreateSprite("C:\\Users\\carva\\Documents\\GTech\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Resources\\Player.png");
	mPlayerLeft->Init(playerLeftSprite, { 50, (WindowHeight / 2.f) - (playerLeftSprite->GetSize().y / 2.f) });
	mPlayerRight->Init(playerRightSprite, { WindowWidth - 50.f - playerRightSprite->GetSize().x, (WindowHeight / 2.f) - (playerLeftSprite->GetSize().y / 2.f) });
	mEntities.emplace_back(mPlayerLeft);
	mEntities.emplace_back(mPlayerRight);

	Sprite* ballSprite = mWindow->CreateSprite("C:\\Users\\carva\\Documents\\GTech\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Encapsulation-SDL-Raylib\\Resources\\Ball.png");
	mBall->Init(ballSprite, { (WindowWidth / 2.f) - (ballSprite->GetSize().x / 2.f), (WindowHeight / 2.f) + (ballSprite->GetSize().y / 2.f) });
	mBall->SetDirection({ 0.1f, 0.5f });
	mEntities.emplace_back(mBall);
}

void Game::Loop()
{
	while (mWindow->IsWindowOpen())
	{
		mTimeManager->OnFrameStart();
		mWindow->ProcessEvents();
		for (std::list<Entity*>::iterator it = mEntities.begin(); it != mEntities.end(); ++it)
		{
			(*it)->Update();

			for (std::list<Entity*>::iterator subIt = it; subIt != mEntities.end(); ++subIt)
			{

				if ((*it)->CheckCollision(*subIt))
				{
					if (Ball* ball = dynamic_cast<Ball*>(*it))
					{
						ball->OnCollideWithPlayer();
					}
					else if (Ball* ball = dynamic_cast<Ball*>(*it))
					{
						ball->OnCollideWithPlayer();
					}
				}
			}
		}

		mWindow->BeginDraw();
		mWindow->DrawText(std::to_string(static_cast<int>(round(1 / mTimeManager->GetElapsedTime())))+" FPS", 980, 50, 20);
		for (std::list<Entity*>::iterator it = mEntities.begin(); it != mEntities.end(); ++it)
		{
			mWindow->DrawEntity(*it);
		}
		mWindow->EndDraw();

		mTimeManager->ApplyFramerateLimit();
	}

	mWindow->DestroyWindow();
}

void Game::OnGoal(bool leftSide)
{
	if (leftSide)
	{
		mPlayerLeft->IncrementPoints(INCREMENT_POINTS);
	}
	else
	{
		mPlayerRight->IncrementPoints(INCREMENT_POINTS);
	}
}
