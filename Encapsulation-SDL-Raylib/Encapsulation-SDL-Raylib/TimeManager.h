#pragma once
class TimeManager
{

	virtual void SetMaxFramerate(int Framerate) = 0;
	virtual float GetTime() = 0;
	virtual void OnFrameStart() = 0;
	virtual float GetElapsedTime() = 0;
	virtual void ApplyFramerateLimit() = 0;

};

