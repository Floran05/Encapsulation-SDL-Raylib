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

Custom::Vector2<int> SpriteRaylib::GetSize()
{
	if (mImage.id == 0) { return Custom::Vector2<int>(); }
	return Custom::Vector2<int>(mImage.width, mImage.height);
}
