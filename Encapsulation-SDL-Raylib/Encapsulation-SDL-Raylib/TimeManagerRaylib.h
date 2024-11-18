#pragma once

#include "TimeManager.h"

class TimeManagerRaylib : public TimeManager
{
private :
	int mMaxFrameRate;
public : 
	TimeManagerRaylib();
	~TimeManagerRaylib();
	void SetMaxFramerate(int Framerate) override; 
	float GetTime() override;
	void OnFrameStart() override;
	float GetElapsedTime() override; 
	void ApplyFramerateLimit() override;
};

