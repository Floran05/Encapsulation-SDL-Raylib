#pragma once

#include "Singleton.h"

enum class ELib {
	SDL,
	Raylib
};

class Game : public Singleton<Game>
{
public:

	Game(const ELib& Library);

	void Init();

};

