#pragma once

#include "Window.h"
#include "raylib.h"

class WindowRaylib : public Window
{
public:

	WindowRaylib();
	~WindowRaylib();

private:

	Font mFont;

public:

	virtual void InitLibrary() override;
	virtual void CreateWindow(const std::string& WindowTitle, int Width, int Height) override;
	virtual bool IsWindowOpen() override;
	virtual Sprite* CreateSprite(const std::string& PathToTexture) override;
	virtual void LoadFont(const std::string& PathToFontFile) override;
	virtual void DrawEntity(Entity* Entity) override;
	virtual void ProcessEvents() override;
	virtual void BeginDraw() override;
	virtual void EndDraw() override;
	virtual void DrawText(const std::string& Text , int PosX , int PosY , int FontSize) override;
	virtual void DestroyWindow() override;
	virtual Custom::Vector2f GetWindowSize() override;
};
