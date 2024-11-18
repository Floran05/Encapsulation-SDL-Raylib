#pragma once

#include "TimeManager.h"

class TimeManagerSDL : public TimeManager
{
public:

	TimeManagerSDL();
	virtual ~TimeManagerSDL();

private:

	int mMaxFramerate;
	float mTimeOnLastFrame;

public:

	virtual void SetMaxFramerate(int Framerate) override;
	virtual float GetTime() override;
	virtual void OnFrameStart() override;
	virtual float GetElapsedTime() override;
	virtual void ApplyFramerateLimit() override;
};

