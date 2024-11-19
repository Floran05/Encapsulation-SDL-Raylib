#include "TimeManagerSDL.h"

#include <SDL2/SDL.h>

TimeManagerSDL::TimeManagerSDL()
	: mTimeOnLastFrame(0.f)
{
	mMaxFrameRate = -1;
}

TimeManagerSDL::~TimeManagerSDL()
{
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
	mTimeOnLastFrame = GetTime();
}

float TimeManagerSDL::GetElapsedTime()
{
	return GetTime() - mTimeOnLastFrame;
}

void TimeManagerSDL::ApplyFramerateLimit()
{
	if (mMaxFrameRate < 1) return;

	float elapsedTime = GetElapsedTime();

	SDL_Delay(floor((1000.f / mMaxFrameRate) - (elapsedTime * 1000)));
}
