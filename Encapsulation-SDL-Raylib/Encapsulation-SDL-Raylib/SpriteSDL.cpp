#include "SpriteSDL.h"

#include <iostream>
#include <SDL2/SDL_image.h>

SpriteSDL::SpriteSDL()
{
}

SpriteSDL::~SpriteSDL()
{
	SDL_FreeSurface(mImage);
	mImage = nullptr;
}

void SpriteSDL::Load(const std::string& PathToFile)
{
	mImage = IMG_Load(PathToFile.c_str());

	if (!mImage)
	{
		std::cerr << "Can't load sprite image: " << SDL_GetError() << std::endl;
	}
}
