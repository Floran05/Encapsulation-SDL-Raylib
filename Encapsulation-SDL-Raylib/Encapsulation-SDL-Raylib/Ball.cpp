#include "Ball.h"
#include"Game.h"
#include"Window.h"
#include "Sprite.h"

Ball::Ball()
	: mCurrentTarget(nullptr)
	, mOldTarget(nullptr)
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
	if (IsColliding && mCurrentTarget != mOldTarget) {
		Move(-mDirection.x, mDirection.y);
		mSpeedMultiplier *= 1.2f;
		IsColliding = false;
		mOldTarget = mCurrentTarget;
		mCurrentTarget = nullptr;
	}
	if (mPosition.x + mSprite->GetSize().x < 0) {
		I(Game)->OnGoal(false);
		ResetPosition();
	}
	if (mPosition.x  > I(Game)->GetWindow()->GetWindowSize().x) {
		I(Game)->OnGoal(true);
		ResetPosition();
	}
}

void Ball::OnCollideWithPlayer(Entity* Target)
{
	IsColliding = true;
	mCurrentTarget = Target;
}

void Ball::ResetPosition()
{
	mSpeedMultiplier = INITIAL_SPEED;
	const float randAngle = rand() * 1.f / RAND_MAX;
	mPosition = { (I(Game)->GetWindow()->GetWindowSize().x * 0.5f) - (mSprite->GetSize().x * 0.5f), ((I(Game)->GetWindow()->GetWindowSize().y * 0.5f) + (mSprite->GetSize().y * 0.5f)) };
	/*float x = static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f; 
	float y = static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f;*/
	bool isRight = std::rand() % 2 == 0;
	float minAngle = isRight ? 30.f : 120.0f;
	float maxAngle = isRight ? 60.0f : 150.0f;
	float angle = minAngle + static_cast<float>(std::rand()) / RAND_MAX * (maxAngle - minAngle);
	angle = angle * (3.14159265f / 180.0f); 
	float x = std::cos(angle);
	float y = std::sin(angle);
	SetDirection(Custom::Vector2f{ x, y });

	mCurrentTarget = nullptr;
	mOldTarget = nullptr;
}




