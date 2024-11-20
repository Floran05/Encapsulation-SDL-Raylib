#include "PlayerSDL.h"

#include "SpriteSDL.h"

PlayerSDL::PlayerSDL()
{
}

PlayerSDL::~PlayerSDL()
{
}

void PlayerSDL::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteSDL();
	mSprite->Load(PathToTexture);
}
