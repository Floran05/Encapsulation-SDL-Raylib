#pragma once

#include "Player.h"

class PlayerSDL : public Player
{
public:

	PlayerSDL();
	virtual ~PlayerSDL();

public:

	virtual void Init(const std::string& PathToTexture) override;

};

