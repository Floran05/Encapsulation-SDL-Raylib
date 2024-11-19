#pragma once

#include "Controller.h"

#include <set>

class ControllerSDL : public Controller
{
public:

	ControllerSDL();
	virtual ~ControllerSDL();

private:

	std::set<int> pressedKeys;

public:

	virtual bool IsKeyDown(int Key) override;

	virtual void AddKeyToListOfPressedKey(int Key);
	virtual void ResetPressedKeys();

};

