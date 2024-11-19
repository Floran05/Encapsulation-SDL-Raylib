#pragma once

#include "Entity.h"

class Player : public Entity
{
private:

	int mPoints;

public:

	int GetPoints() const { return mPoints; }

	virtual void Update(float DeltaTime) = 0;
	virtual void Move(float X, float Y) override;

};

