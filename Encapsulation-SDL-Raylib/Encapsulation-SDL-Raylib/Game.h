#pragma once

#include "Singleton.h"

enum class ELibrary {
	SDL,
	Raylib
};

class Window;

class Game : public Singleton<Game>
{
public:

	Game();

private:

	ELibrary mSelectedLibrary;

	Window* mWindow;

public:

	void Init(const ELibrary& Library);

	void Loop();

};

