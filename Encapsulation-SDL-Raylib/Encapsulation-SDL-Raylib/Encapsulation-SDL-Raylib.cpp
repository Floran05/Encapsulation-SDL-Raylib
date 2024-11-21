#define SDL_MAIN_HANDLED

#include "Game.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	srand(time(NULL));

	ELibrary selectedLibrary = ELibrary::SDL;

	if (argc > 1)
	{
		if (strcmp(argv[1], "-raylib") == 0)
		{
			selectedLibrary = ELibrary::Raylib;
		}
		else if (strcmp(argv[1], "-sdl") == 0)
		{
			selectedLibrary = ELibrary::SDL;
		}
	}

	Game* g = I(Game);
	g->Init(selectedLibrary, selectedLibrary == ELibrary::SDL ? "Encapsulation - SDL" : "Encapsulation - Raylib", 1080, 720, 144);
	g->Loop();

	return 0;
}