#include "TimeManagerSDL.h"

#include <SDL2/SDL.h>

TimeManagerSDL::TimeManagerSDL()
	: mMaxFramerate(-1)
	, mTimeOnLastFrame(0.f)
{
}

TimeManagerSDL::~TimeManagerSDL()
{
}

void TimeManagerSDL::SetMaxFramerate(int Framerate)
{
	mMaxFramerate = Framerate;
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
	if (mMaxFramerate < 1) return;

	float elapsedTime = GetElapsedTime();

	SDL_Delay(floor((1000.f / mMaxFramerate) - (elapsedTime * 1000)));
}
