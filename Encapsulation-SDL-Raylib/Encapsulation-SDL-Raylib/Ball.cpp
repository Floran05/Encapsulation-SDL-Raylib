#include "Ball.h"
#include"Game.h"
#include"Window.h"
Ball::Ball()
{
	IsColliding = false;
}

Ball::~Ball()
{
}

void Ball::Update()
{
	Move(mDirection.x, mDirection.y);

	if (mPosition.y < 0 || mPosition.y>I(Game)->GetWindow()->GetWindowSize().y)
	{
		Move(mDirection.x, -mDirection.y);
	}
	if (IsColliding) {
		Move(-mDirection.x, mDirection.y);
		IsColliding = false;
	}
	
}


