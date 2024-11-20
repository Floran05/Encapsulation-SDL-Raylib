#pragma once

#include "Singleton.h"
#include <string>
#include <list>

#define INCREMENT_POINTS 1

enum class ELibrary {
	SDL,
	Raylib
};

class Window;
class Controller;
class TimeManager;
class Player;
class Entity;
class Ball;

class Game : public Singleton<Game>
{
public:

	Game();

private:

	ELibrary mSelectedLibrary;

	Window* mWindow;
	Controller* mController;
	TimeManager* mTimeManager;

	Player* mPlayerLeft;
	Player* mPlayerRight;
	Ball* mBall;

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

	void OnGoal(bool leftSide);
	
};

