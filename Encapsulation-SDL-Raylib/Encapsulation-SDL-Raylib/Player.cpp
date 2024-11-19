#include "Player.h"

#include "Game.h"
#include "Window.h"
#include "Sprite.h"

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
