#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRaylib : public Sprite
{
private :
	Texture2D mImage;
public:

	SpriteRaylib();
	~SpriteRaylib();
	bool Load(const std::string& PathToFile) override;
};

