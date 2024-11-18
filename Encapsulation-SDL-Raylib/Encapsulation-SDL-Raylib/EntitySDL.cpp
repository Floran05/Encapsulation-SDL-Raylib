#include "EntitySDL.h"
#include "SpriteSDL.h"

EntitySDL::EntitySDL()
{
}

EntitySDL::~EntitySDL()
{
}

void EntitySDL::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteSDL();
	mSprite->Load(PathToTexture);
}
