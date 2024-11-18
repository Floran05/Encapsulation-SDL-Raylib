#pragma once

#include "Window.h"
#include "raylib.h"

class WindowRaylib : public Window
{
public:

	WindowRaylib();
	~WindowRaylib();

	virtual void InitLibrary() override;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) override;
	virtual void DrawEntity(Entity* Entity) override;

	virtual void BeginDraw() override;
	virtual void EndDraw() override;

	virtual void DestroyWindow() override;
};

