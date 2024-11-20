#pragma once

#include "Sprite.h"

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class SpriteSDL : public Sprite
{
public:

	SpriteSDL();
	virtual ~SpriteSDL();

private:

	SDL_Texture* mTexture;
	SDL_Renderer* mRenderer;

	Custom::Vector2<int> mSpriteSize;

public:

	virtual bool Load(const std::string& PathToFile) override;
	virtual Custom::Vector2<int> GetSize() override;

	virtual void SetRenderer(SDL_Renderer* renderer) { mRenderer = renderer;  }
	virtual SDL_Texture* GetTexture() const { return mTexture; }

};

