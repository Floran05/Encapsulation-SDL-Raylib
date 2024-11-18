#pragma once

#include "Window.h"

class WindowSDL : public Window
{
public:

	WindowSDL();
	virtual ~WindowSDL();

public:

	virtual void InitLibrary() override;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) override;

};

