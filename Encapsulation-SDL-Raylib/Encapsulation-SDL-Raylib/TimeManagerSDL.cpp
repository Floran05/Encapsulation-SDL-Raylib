#include "TimeManagerSDL.h"

#include <SDL2/SDL.h>

TimeManagerSDL::TimeManagerSDL()
	: mTimeOnLastFrame(0.f)
	, mDeltaTime(0.f)
	, mCurrentFrameIndex(0)
{
	mMaxFrameRate = -1;
	mFrameTimes = std::vector<float>(FRAME_HISTORY_SIZE, 0.f);
}

TimeManagerSDL::~TimeManagerSDL()
{
}

float TimeManagerSDL::ComputeHistoryAverage()
{
	if (mFrameTimes.empty()) return 0.f;
	float total = 0.f;
	for (const float frameTime : mFrameTimes)
	{
		total += frameTime;
	}
	return total / mFrameTimes.size();
}

void TimeManagerSDL::SetMaxFramerate(int Framerate)
{
	mMaxFrameRate = Framerate;
}

float TimeManagerSDL::GetTime()
{
	return SDL_GetTicks() / 1000.f;
}

void TimeManagerSDL::OnFrameStart()
{
	mDeltaTime = GetTime() - mTimeOnLastFrame;
	mTimeOnLastFrame = GetTime();

	mFrameTimes[mCurrentFrameIndex] = mDeltaTime;
	mCurrentFrameIndex = (mCurrentFrameIndex + 1) % FRAME_HISTORY_SIZE;
}

float TimeManagerSDL::GetElapsedTime()
{
	return mDeltaTime;
}

void TimeManagerSDL::ApplyFramerateLimit()
{
	if (mMaxFrameRate < 1) return;

	float elapsedTime = GetElapsedTime();
	float remainingTime = floor((1000.f / mMaxFrameRate) - (elapsedTime * 1000));
	if (remainingTime > 0.f)
	{
		SDL_Delay(remainingTime);
	}
}

float TimeManagerSDL::GetFramerate()
{
	float average = ComputeHistoryAverage();

	return average > 0.f ? round(1.f / ComputeHistoryAverage()) : 0.f;
}
