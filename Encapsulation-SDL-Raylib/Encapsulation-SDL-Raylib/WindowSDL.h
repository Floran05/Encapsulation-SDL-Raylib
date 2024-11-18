#pragma once

#include "Window.h"

class SDL_Surface;
class SDL_Window;

class WindowSDL : public Window
{
public:

	WindowSDL();
	virtual ~WindowSDL();

private:

	SDL_Surface* mWindowSurface;
	SDL_Window* mWindow;

public:

	virtual void InitLibrary() override;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) override;

};

