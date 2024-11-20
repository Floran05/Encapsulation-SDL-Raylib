#define SDL_MAIN_HANDLED

#include "Game.h"

#include <iostream>

int main(int argc, char* argv[])
{
	ELibrary selectedLibrary = ELibrary::Raylib;

	if (argc > 1)
	{
		if (argv[1] == "-raylib")
		{
			selectedLibrary = ELibrary::Raylib;
		}
		else if (argv[1] == "-sdl")
		{
			selectedLibrary = ELibrary::SDL;
		}
	}

	Game* g = I(Game);
	g->Init(selectedLibrary, "Encapsulation - SDL - Raylib", 1080, 720, 60);
	g->Loop();

	//system("pause");

	return 0;
}