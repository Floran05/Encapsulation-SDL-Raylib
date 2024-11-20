#include "SpriteSDL.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SpriteSDL::SpriteSDL()
	: mTexture(nullptr)
	, mRenderer(nullptr)
	, mSpriteSize({ 0, 0 })
{
}

SpriteSDL::~SpriteSDL()
{
	SDL_DestroyTexture(mTexture);
	mTexture = nullptr;
	//SDL_FreeSurface(mImage);
	//mImage = nullptr;
}

bool SpriteSDL::Load(const std::string& PathToFile)
{
	if (!mRenderer) return false;

	SDL_Surface* image = IMG_Load(PathToFile.c_str());

	if (!image)
	{
		std::cerr << "Can't load sprite image: " << IMG_GetError() << std::endl;
		return false;
	}

	mSpriteSize = { image->w, image->h };

	mTexture = SDL_CreateTextureFromSurface(mRenderer, image);
	if (!mTexture)
	{
		std::cerr << "Error creating texture : " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_FreeSurface(image);

	return true;
}

Custom::Vector2<int> SpriteSDL::GetSize()
{
	return mSpriteSize;
}
