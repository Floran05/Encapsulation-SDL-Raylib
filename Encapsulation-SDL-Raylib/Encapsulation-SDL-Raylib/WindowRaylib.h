#pragma once

#include "Window.h"
#include "raylib.h"

class WindowRaylib : public Window
{
	WindowRaylib();
	~WindowRaylib();
	void CreateWindow(const std::string& WindowTitle, int Width, int Height);
	void DrawSprite(Sprite* Sprite);
	void BeginDraw();
	void EndDraw();
};

