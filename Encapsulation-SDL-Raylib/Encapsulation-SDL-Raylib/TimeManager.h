#pragma once
class TimeManager
{

	virtual void SetMaxFramerate(int Framerate) = 0;
	virtual void GetTime() = 0;
	virtual void OnFrameStart() = 0;
	virtual void GetElapsedTime() = 0;

};

