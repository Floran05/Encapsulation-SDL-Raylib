#pragma once

#include "Entity.h"

#define INITIAL_SPEED 500.f

class Ball : public Entity
{
private :

	bool IsColliding;

	Entity* mCurrentTarget;
	Entity* mOldTarget;

public:
	Ball();
	~Ball();
	void Update();
	void OnCollideWithPlayer(Entity* Target);
	void ResetPosition();
	
};

