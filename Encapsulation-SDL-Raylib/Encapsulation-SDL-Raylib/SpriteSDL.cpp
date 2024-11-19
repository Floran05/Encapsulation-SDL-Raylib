#include "SpriteSDL.h"

#include <iostream>
#include <SDL2/SDL_image.h>

SpriteSDL::SpriteSDL()
	: mImage(nullptr)
{
}

SpriteSDL::~SpriteSDL()
{
	SDL_FreeSurface(mImage);
	mImage = nullptr;
}

bool SpriteSDL::Load(const std::string& PathToFile)
{
	mImage = IMG_Load(PathToFile.c_str());

	if (!mImage)
	{
		std::cerr << "Can't load sprite image: " << IMG_GetError() << std::endl;
		return false;
	}

	return true;
}

Custom::Vector2<int> SpriteSDL::GetSize()
{
	if (!mImage) return Custom::Vector2<int>();

	return Custom::Vector2<int>(mImage->w, mImage->h);
}
