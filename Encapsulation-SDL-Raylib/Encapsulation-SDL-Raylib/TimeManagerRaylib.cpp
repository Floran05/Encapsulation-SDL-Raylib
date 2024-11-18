#include "TimeManagerRaylib.h"
#include "raylib.h"
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
}

float TimeManagerRaylib::GetTime()
{
	return ::GetTime() / 1000.f;
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
	SetTargetFPS(mMaxFrameRate);
}
