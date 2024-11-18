#pragma once

#include "Window.h"

struct SDL_Surface;
struct SDL_Window;

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
	virtual void DrawEntity(Entity* Entity) override;

	virtual void BeginDraw() override;
	virtual void EndDraw() override;

	virtual void DestroyWindow() override;

};

