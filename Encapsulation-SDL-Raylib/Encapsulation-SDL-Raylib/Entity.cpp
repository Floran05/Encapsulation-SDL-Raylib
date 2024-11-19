#include "Entity.h"

Entity::Entity()
	: mSprite(nullptr)
	, mPosition({ 0.f, 0.f })
	, mDirection({ 0.f, 0.f })
	, mSpeedMultiplier(1.f)
{
}

Entity::~Entity()
{
}

void Entity::Move(float X, float Y)
{
}
