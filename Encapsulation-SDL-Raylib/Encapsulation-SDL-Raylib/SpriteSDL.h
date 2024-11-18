#pragma once

#include "Sprite.h"

struct SDL_Surface;

class SpriteSDL : public Sprite
{
public:

	SpriteSDL();
	virtual ~SpriteSDL();

private:

	SDL_Surface* mImage;

public:

	virtual void Load(const std::string& PathToFile) override;

};

