#pragma once

#include "Entity.h"

class Ball : public Entity
{

public:
	Ball();
	~Ball();
	void Update();
	void CheckCollision();
	//void Draw();
};

