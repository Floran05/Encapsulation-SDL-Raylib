#include "Ball.h"
#include"Game.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update()
{
	Move(mDirection.x, mDirection.y);

	if (mPosition.y < 0)
	{
		Move(mDirection.x, -mDirection.y);
	}
}

void Ball::CheckCollision()
{
}
