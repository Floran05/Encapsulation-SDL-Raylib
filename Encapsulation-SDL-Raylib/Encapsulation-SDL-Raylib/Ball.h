#pragma once

#include "Entity.h"

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

