#include "Entity.h"

#include "Game.h"
#include "TimeManager.h"

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
	const float deltaTime = I(Game)->GetTimeManager()->GetElapsedTime();
	mPosition += Custom::Vector2f(X * deltaTime * mSpeedMultiplier, Y * deltaTime * mSpeedMultiplier);
}
