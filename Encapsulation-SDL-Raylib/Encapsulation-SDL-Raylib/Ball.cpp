#include "Ball.h"
#include"Game.h"
#include"Window.h"
#include "Sprite.h"

Ball::Ball()
{
	IsColliding = false;
	mSpeedMultiplier = INITIAL_SPEED;
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
		mSpeedMultiplier *= 1.2;
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
	mSpeedMultiplier = INITIAL_SPEED;
	const float randAngle = rand() * 1.f / RAND_MAX;
	mPosition = { (I(Game)->GetWindow()->GetWindowSize().x * 0.5f) - (mSprite->GetSize().x * 0.5f), ((I(Game)->GetWindow()->GetWindowSize().y * 0.5f) + (mSprite->GetSize().y * 0.5f)) };
}


