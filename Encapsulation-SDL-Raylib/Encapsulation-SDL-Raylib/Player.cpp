#include "Player.h"

#include "Game.h"
#include "Controller.h"
#include "Window.h"
#include "Sprite.h"

void Player::SetControlKeys(int UpKey, int DownKey)
{
	mUpKey = UpKey;
	mDownKey = DownKey;
}

void Player::Update()
{
	Controller* controller = I(Game)->GetController();

	if (controller->IsKeyDown(mDownKey))
	{
		Move(0, 1);
	}
	else if (controller->IsKeyDown(mUpKey))
	{
		Move(0, -1);
	}
}

void Player::Move(float X, float Y)
{
	Entity::Move(0, Y);

	if (mPosition.y < 0)
	{
		mPosition.y = 0;
	}

	const int windowHeight = I(Game)->GetWindow()->GetWindowSize().y;
	const int spriteHeight = GetSprite()->GetSize().y;
	if (mPosition.y > windowHeight - spriteHeight)
	{
		mPosition.y = windowHeight - spriteHeight;
	}
}
