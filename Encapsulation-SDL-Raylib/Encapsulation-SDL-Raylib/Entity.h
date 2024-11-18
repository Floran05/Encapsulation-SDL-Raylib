#pragma once

#include "Vector2.h"

class Entity
{
public:

	Entity();
	virtual ~Entity();

private:

	Vector2<float> mPosition;

public:

	void Move();


};

