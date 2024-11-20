#include "Ball.h"
#include"Game.h"
#include"Window.h"
#include "Sprite.h"

Ball::Ball()
{
	IsColliding = false;
	mSpeedMultiplier = 500.f;
}

Ball::~Ball()
{
}

void Ball::Update()
{
	Move(mDirection.x, mDirection.y);

	if (mPosition.y < 0 || mPosition.y>I(Game)->GetWindow()->GetWindowSize().y - mSprite->GetSize().y)
	{
		Move(mDirection.x, -mDirection.y);
	}
	if (IsColliding) {
		Move(-mDirection.x, mDirection.y);
		IsColliding = false;
	}
	
}


