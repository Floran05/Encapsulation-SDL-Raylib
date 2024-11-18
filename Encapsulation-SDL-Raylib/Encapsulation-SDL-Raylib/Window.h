#pragma once

class Sprite;

class Window
{
public:

	virtual void InitLibrary() = 0;
	virtual void CreateWindow() = 0;
	virtual void DrawSprite(Sprite* Sprite) = 0;

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;

};

