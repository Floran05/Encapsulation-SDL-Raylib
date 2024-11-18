#pragma once

#include <string>

class Sprite;

class Window
{
public:

	virtual void InitLibrary() = 0;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) = 0;
	virtual void DrawSprite(Sprite* Sprite) = 0;

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;

};

