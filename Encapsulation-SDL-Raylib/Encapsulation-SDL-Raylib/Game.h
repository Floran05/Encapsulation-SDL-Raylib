#pragma once

#include "Singleton.h"
#include <string>
#include <list>

enum class ELibrary {
	SDL,
	Raylib
};

class Window;
class Controller;
class TimeManager;
class Player;
class Entity;

class Game : public Singleton<Game>
{
public:

	Game();

private:

	ELibrary mSelectedLibrary;

	Window* mWindow;
	Controller* mController;
	TimeManager* mTimeManager;

	std::list<Entity*> mEntities;

public:

	Controller* GetController() const { return mController; }
	Window* GetWindow() const { return mWindow; }
	TimeManager* GetTimeManager() const { return mTimeManager; }
	void Init(
		const ELibrary& Library, 
		const std::string& WindowTitle, 
		int WindowWidth, 
		int WindowHeight, 
		int MaxFramerate);

	void Loop();
	
};

