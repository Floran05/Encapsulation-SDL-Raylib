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

	virtual bool Load(const std::string& PathToFile) override;

	virtual SDL_Surface* GetImage() const { return mImage; }

};

