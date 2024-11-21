#include "WindowSDL.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "Game.h"
#include "SpriteSDL.h"
#include "ControllerSDL.h"

WindowSDL::WindowSDL()
	: mWindow(nullptr)
	, mRenderer(nullptr)
	, mFont(nullptr)
	, mWindowOpen(true)
{
}

WindowSDL::~WindowSDL()
{
	delete mFont;
	delete mRenderer;
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
		SDL_Quit();
		system("pause");
		exit(1);
	}

	if (TTF_Init() < 0)
	{
		std::cerr << "Error Initializing SDL_TTF : " << TTF_GetError() << std::endl;
		SDL_Quit();
		IMG_Quit();
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

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!mRenderer)
	{
		std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
		system("pause");
		exit(1);
	}
}

bool WindowSDL::IsWindowOpen()
{
	return mWindowOpen;
}

Sprite* WindowSDL::CreateSprite(const std::string& PathToTexture)
{
	if (!mRenderer) return nullptr;

	SpriteSDL* sprite = new SpriteSDL();
	sprite->SetRenderer(mRenderer);
	sprite->Load(PathToTexture);
	return sprite;
}

void WindowSDL::LoadFont(const std::string& PathToFontFile)
{
	mFont = TTF_OpenFont(PathToFontFile.c_str(), 100);
}

void WindowSDL::ProcessEvents()
{
	SDL_Event ev;

	ControllerSDL* controller = dynamic_cast<ControllerSDL*>(I(Game)->GetController());
	while (SDL_PollEvent(&ev) != 0)
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			mWindowOpen = false;
			break;
		case SDL_KEYDOWN:
			controller->AddKeyToListOfPressedKeys(ev.key.keysym.sym);
			break;
		case SDL_KEYUP:
			controller->RemoveKeyFromListOfPressedKeys(ev.key.keysym.sym);
			break;
		}
	}
}

void WindowSDL::DrawEntity(Entity* Entity)
{
	if (!mWindow || !mRenderer) return;
	SpriteSDL* sdlSprite = dynamic_cast<SpriteSDL*>(Entity->GetSprite());
	if (!sdlSprite) return;

	SDL_Rect targetRect;
	targetRect.x = static_cast<int>(Entity->GetPosition().x);
	targetRect.y = static_cast<int>(Entity->GetPosition().y);
	targetRect.w = sdlSprite->GetSize().x;
	targetRect.h = sdlSprite->GetSize().y;

	SDL_RenderCopy(mRenderer, sdlSprite->GetTexture(), NULL, &targetRect);
}

void WindowSDL::DrawText(const std::string& Text, int PosX, int PosY, int FontSize)
{
	if (!mFont || !mRenderer) return;
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, Text.c_str(), { 255, 255, 255 });
	TTF_SetFontSize(mFont, FontSize);
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
	Custom::Vector2<int> textureSize;
	SDL_QueryTexture(texture, NULL, NULL, &textureSize.x, &textureSize.y);
	SDL_FreeSurface(textSurface);
	if (!texture)
	{
		std::cerr << "Error creating texture : " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Rect targetRect;
	targetRect.x = PosX;
	targetRect.y = PosY;
	targetRect.w = (textureSize.x / textureSize.y) * FontSize;
	targetRect.h = FontSize;
	SDL_RenderCopy(mRenderer, texture, NULL, &targetRect);
	SDL_DestroyTexture(texture);
}

void WindowSDL::BeginDraw()
{
	if (!mWindow || !mRenderer) return;
	SDL_RenderClear(mRenderer);
}

void WindowSDL::EndDraw()
{
	if (!mWindow || !mRenderer) return;
	SDL_RenderPresent(mRenderer);
}

void WindowSDL::DestroyWindow()
{
	if (!mWindow) return;
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	mWindow = nullptr;
	mRenderer = nullptr;

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

Custom::Vector2f WindowSDL::GetWindowSize()
{
	if (!mWindow) return Custom::Vector2f();
	int width = 0;
	int height = 0;
	SDL_GetWindowSize(mWindow, &width, &height);
	return Custom::Vector2f(width * 1.f, height * 1.f);
}


