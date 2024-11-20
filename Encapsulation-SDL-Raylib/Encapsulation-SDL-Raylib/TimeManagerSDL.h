#pragma once

#include "TimeManager.h"

#include <vector>

#define FRAME_HISTORY_SIZE 60

class TimeManagerSDL : public TimeManager
{
public:

	TimeManagerSDL();
	virtual ~TimeManagerSDL();

private:

	float mTimeOnLastFrame;
	float mDeltaTime;

	std::vector<float> mFrameTimes;
	int mCurrentFrameIndex;

private:

	float ComputeHistoryAverage();

public:

	virtual void SetMaxFramerate(int Framerate) override;
	virtual float GetTime() override;
	virtual void OnFrameStart() override;
	virtual float GetElapsedTime() override;
	virtual void ApplyFramerateLimit() override;
	virtual float GetFramerate() override;
};

