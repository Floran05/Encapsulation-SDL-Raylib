#include "EntityRaylib.h"
#include "SpriteRaylib.h"
EntityRaylib::EntityRaylib()
{
}

EntityRaylib::~EntityRaylib()
{
}

void EntityRaylib::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteRaylib();
	mSprite->Load(PathToTexture);
}
