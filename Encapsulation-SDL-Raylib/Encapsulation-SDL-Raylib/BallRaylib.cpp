#include "BallRaylib.h"
#include "SpriteRaylib.h"
BallRaylib::BallRaylib()
{
}

BallRaylib::~BallRaylib()
{
}

void BallRaylib::Init(const std::string& PathToTexture)
{
	mSprite = new SpriteRaylib();
	mSprite->Load(PathToTexture);

}
