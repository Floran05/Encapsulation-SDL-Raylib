#pragma once

#include <string>

class Entity;

class Window
{
public:

	virtual void InitLibrary() = 0;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) = 0;
	virtual bool IsWindowOpen() = 0;

	virtual void ProcessEvents() = 0;
	
	virtual void BeginDraw() = 0;
	virtual void DrawEntity(Entity* Entity) = 0;
	virtual void DrawText(const std::string& Text , int PosX , int PosY , int fontSize) = 0;
	virtual void EndDraw() = 0;

	virtual void DestroyWindow() = 0;

};

