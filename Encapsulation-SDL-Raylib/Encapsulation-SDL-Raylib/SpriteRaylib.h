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
	virtual bool Load(const std::string& PathToFile) override;
	virtual Texture2D GetTexture();
	virtual Custom::Vector2<int> GetSize() override;
};

