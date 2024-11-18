#pragma once
#include "Entity.h"
class EntityRaylib : public Entity
{
public:

	EntityRaylib();
	virtual ~EntityRaylib();

public:

	virtual void Init(const std::string& PathToTexture) override;

};

