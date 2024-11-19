#include "SpriteRaylib.h"
#include <iostream>
SpriteRaylib::SpriteRaylib()
{
}

SpriteRaylib::~SpriteRaylib()
{
	UnloadTexture(mImage);
}

bool SpriteRaylib::Load(const std::string& PathToFile)
{
	mImage = LoadTexture(PathToFile.c_str());
	if (mImage.id == 0) {
		std::cerr << "Can't load sprite " << PathToFile << std::endl;
		return false;
	}

	return true;
}

Texture2D SpriteRaylib::GetTexture()
{
	return mImage;
}
