#include "TimeManagerRaylib.h"
#include "raylib.h"
#include <math.h>

TimeManagerRaylib::TimeManagerRaylib()
{
	mMaxFrameRate = 0;
}

TimeManagerRaylib::~TimeManagerRaylib()
{
}

void TimeManagerRaylib::SetMaxFramerate(int Framerate)
{
	mMaxFrameRate = Framerate;
	SetTargetFPS(mMaxFrameRate);
}

float TimeManagerRaylib::GetTime()
{
	return static_cast<float>(::GetTime()) ;
}

void TimeManagerRaylib::OnFrameStart()
{
}

float TimeManagerRaylib::GetElapsedTime()
{
	return GetFrameTime();
}

void TimeManagerRaylib::ApplyFramerateLimit()
{
}

float TimeManagerRaylib::GetFramerate()
{
	float frameTime = GetFrameTime();
	return static_cast<float>(frameTime > 0.f ? round(1.f / frameTime) : 0.f);
}
