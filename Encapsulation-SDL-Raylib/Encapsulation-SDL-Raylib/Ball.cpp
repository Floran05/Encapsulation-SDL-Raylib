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
	if (mPosition.x - mSprite->GetSize().x < 0) {
		I(Game)->OnGoal(false);
		ResetPosition();
	}
	if (mPosition.x  > I(Game)->GetWindow()->GetWindowSize().x) {
		I(Game)->OnGoal(true);
		ResetPosition();
	}
}

void Ball::ResetPosition()
{
	mPosition = { (I(Game)->GetWindow()->GetWindowSize().x / 2.f) - (mSprite->GetSize().x / 2.f), ((I(Game)->GetWindow()->GetWindowSize().y / 2.f) + (mSprite->GetSize().y / 2.f)) };
}


