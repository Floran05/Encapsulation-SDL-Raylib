#include "EntitySDL.h"
#include "SpriteSDL.h"

EntitySDL::EntitySDL()
{
	mPosition = { 0.f, 0.f };
}

EntitySDL::~EntitySDL()
{
}

void EntitySDL::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteSDL();
	mSprite->Load(PathToTexture);
}
