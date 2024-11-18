#define SDL_MAIN_HANDLED

#include "Game.h"
#include "WindowSDL.h"

int main(int argc, char* argv[])
{
	Window* w = new WindowSDL();
	w->InitLibrary();
	w->CreateWindow("Test", 400, 300);

	system("pause");

	return 0;
}