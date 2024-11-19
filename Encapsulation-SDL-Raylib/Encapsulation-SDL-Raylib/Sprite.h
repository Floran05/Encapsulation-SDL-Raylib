#pragma once

#include <string>
#include "Vector2.h"

class Sprite
{
public:

	virtual bool Load(const std::string& PathToFile) = 0;
	virtual Custom::Vector2<int> GetSize() = 0;

};

