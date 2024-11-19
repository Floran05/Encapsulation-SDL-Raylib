#pragma once

#include "Controller.h"

class ControllerRaylib : public Controller
{
	virtual bool IsKeyDown(int Key) override; 
};

