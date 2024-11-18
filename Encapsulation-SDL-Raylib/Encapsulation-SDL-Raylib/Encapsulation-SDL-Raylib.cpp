#define SDL_MAIN_HANDLED

#include "Game.h"

#include <iostream>

int main(int argc, char* argv[])
{
	ELibrary selectedLibrary = ELibrary::SDL;

	if (argc > 1 && argv[1] == "-raylib")
	{
		selectedLibrary = ELibrary::Raylib;
	}

	Game* g = I(Game);
	g->Init(selectedLibrary);

	system("pause");

	return 0;
}