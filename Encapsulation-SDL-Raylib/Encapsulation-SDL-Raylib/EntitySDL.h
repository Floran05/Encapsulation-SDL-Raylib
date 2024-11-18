#pragma once
#include "Entity.h"
class EntitySDL : public Entity
{
public:

	EntitySDL();
	virtual ~EntitySDL();

public:

	virtual void Init(const std::string& PathToTexture) override;

};

