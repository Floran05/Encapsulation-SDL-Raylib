#pragma once

#include <string>
#include "Vector2.h"

class Entity;
class Sprite;

class Window
{
public:

	virtual void InitLibrary() = 0;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) = 0;
	virtual bool IsWindowOpen() = 0;
	virtual Sprite* CreateSprite(const std::string& PathToTexture) = 0;

	virtual void ProcessEvents() = 0;
	
	virtual void BeginDraw() = 0;
	virtual void DrawEntity(Entity* Entity) = 0;
	virtual void DrawText(const std::string& Text , int PosX , int PosY , int fontSize) = 0;
	virtual void EndDraw() = 0;

	virtual void DestroyWindow() = 0;

	virtual Custom::Vector2f GetWindowSize() = 0;

};

