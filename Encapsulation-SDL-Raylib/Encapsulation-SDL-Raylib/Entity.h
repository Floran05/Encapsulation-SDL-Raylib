#pragma once

#include <string>

#include "Vector2.h"

class Sprite;

class Entity
{
public:

	Entity();
	virtual ~Entity();

protected:

	Sprite* mSprite;

	Custom::Vector2f mPosition;
	Custom::Vector2f mDirection;

	float mSpeedMultiplier;

public:

	Sprite* GetSprite() const { return mSprite; }
	Custom::Vector2f GetPosition() const { return mPosition; }
	Custom::Vector2f GetDirection() const { return mDirection; }

	virtual void Init(Sprite* sprite);

	virtual void Update() = 0;
	virtual void Move(float X, float Y);
	virtual void CheckCollision(Entity* Target);

};

