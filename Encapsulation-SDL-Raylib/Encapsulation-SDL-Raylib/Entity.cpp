#include "Entity.h"

#include "Game.h"
#include "TimeManager.h"
#include"Sprite.h"
#include <iostream>

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

void Entity::Init(Sprite* sprite, const Custom::Vector2f& InitialPosition)
{
	mSprite = sprite;
	mPosition = InitialPosition;
}

void Entity::Move(float X, float Y)
{
	const float deltaTime = I(Game)->GetTimeManager()->GetElapsedTime();
	mPosition += Custom::Vector2f(X * deltaTime * mSpeedMultiplier, Y * deltaTime * mSpeedMultiplier);
	mDirection = Custom::Vector2f(X, Y);
}

bool Entity::CheckCollision(Entity* Target)
{
	if (this == Target) return false;

	bool overlapX = mPosition.x < Target->GetPosition().x + Target->GetSprite()->GetSize().x &&
					mPosition.x + mSprite->GetSize().x > Target->GetPosition().x;
	bool overlapY = mPosition.y < Target->GetPosition().y + Target->GetSprite()->GetSize().y &&
					mPosition.y + mSprite->GetSize().y > Target->GetPosition().y;

	return overlapX && overlapY;
	

}
