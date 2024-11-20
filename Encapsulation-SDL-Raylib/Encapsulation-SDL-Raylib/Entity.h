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
	void SetDirection(const Custom::Vector2f& direction) { mDirection = direction; }

	virtual void Init(Sprite* sprite, const Custom::Vector2f& InitialPosition = {0.f, 0.f});

	virtual void Update() = 0;
	virtual void Move(float X, float Y);
	virtual bool CheckCollision(Entity* Target);

};

