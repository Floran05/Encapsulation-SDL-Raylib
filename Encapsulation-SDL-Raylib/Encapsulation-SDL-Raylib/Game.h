#pragma once

#include "Singleton.h"
#include <string>

enum class ELibrary {
	SDL,
	Raylib
};

class Window;
class Controller;
class TimeManager;

class Game : public Singleton<Game>
{
public:

	Game();

private:

	bool mRunning;

	ELibrary mSelectedLibrary;

	Window* mWindow;
	Controller* mController;
	TimeManager* mTimeManager;

public:

	Controller* GetController() const { return mController; }

	void Init(
		const ELibrary& Library, 
		const std::string& WindowTitle, 
		int WindowWidth, 
		int WindowHeight, 
		int MaxFramerate);

	void Loop();
	void StopRunning();

};

