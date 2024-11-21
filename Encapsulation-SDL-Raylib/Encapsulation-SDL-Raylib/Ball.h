#pragma once

#include "Entity.h"

#define INITIAL_SPEED 500.f

class Ball : public Entity
{
private :
	bool IsColliding;
public:
	Ball();
	~Ball();
	void Update();
	void OnCollideWithPlayer() { IsColliding = true; }
	void ResetPosition();
	
};

