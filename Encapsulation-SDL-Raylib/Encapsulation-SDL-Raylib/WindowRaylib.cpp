#include "WindowRaylib.h"
#include <iostream>
#include "Entity.h"
#include"SpriteRaylib.h"
WindowRaylib::WindowRaylib()
{
}

WindowRaylib::~WindowRaylib()
{
}

void WindowRaylib::InitLibrary()
{
}

void WindowRaylib::CreateWindow(const std::string& WindowTitle, int Width, int Height)
{
	InitWindow(Width, Height, WindowTitle.c_str());
	if (!IsWindowReady()) {
		std::cerr << "Error creating Reylib window:" << std::endl;
		return ;
	}
}

bool WindowRaylib::IsWindowOpen()
{
	return !WindowShouldClose();
}

Sprite* WindowRaylib::CreateSprite(const std::string& PathToTexture)
{
	SpriteRaylib* sprite = new SpriteRaylib();
	sprite->Load(PathToTexture);
	return sprite;
}

void WindowRaylib::LoadFont(const std::string& PathToFontFile)
{
	mFont = ::LoadFont(PathToFontFile.c_str());
}

void WindowRaylib::DrawEntity(Entity* Entity)
{
	Vector2 Position;
	Position.x = Entity->GetPosition().x;
	Position.y = Entity->GetPosition().y;
	SpriteRaylib* sprite = dynamic_cast<SpriteRaylib*>(Entity->GetSprite());
	DrawTexture(sprite->GetTexture(), Position.x, Position.y, WHITE);
}

void WindowRaylib::ProcessEvents()
{
}

void WindowRaylib::BeginDraw()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

void WindowRaylib::DrawText(const std::string& Text , int PosX, int PosY,int FontSize)
{
	Vector2 pos = { PosX, PosY };
	::DrawTextEx(mFont, Text.c_str(), pos, FontSize, 1.f, WHITE);
}

void WindowRaylib::EndDraw()
{	
	EndDrawing();
}

void WindowRaylib::DestroyWindow()
{
	CloseWindow();
}

Custom::Vector2f WindowRaylib::GetWindowSize()
{
	
	if (!IsWindowReady()) { return Custom::Vector2f(); }
	int width = 0;
	int height = 0;
	width = GetScreenWidth();
	height = GetScreenHeight();
	return Custom::Vector2f(width,height);
}
