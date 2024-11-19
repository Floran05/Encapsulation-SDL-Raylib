#include "EntityRaylib.h"
#include "SpriteRaylib.h"
EntityRaylib::EntityRaylib()
{
	mPosition = { 0.f, 0.f };
}

EntityRaylib::~EntityRaylib()
{
}

void EntityRaylib::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteRaylib();
	mSprite->Load(PathToTexture);
}
