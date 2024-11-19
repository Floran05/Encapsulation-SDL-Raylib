#include "WindowRaylib.h"
#include <iostream>
#include "Entity.h"
#include"SpriteRaylib.h"
WindowRaylib::WindowRaylib() {

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

void WindowRaylib::DrawEntity(Entity* Entity)
{
	Vector2 Position;
	Position.x = Entity->GetPosition().x;
	Position.y = Entity->GetPosition().y;
	SpriteRaylib* sprite = dynamic_cast<SpriteRaylib*>(Entity->GetSprite());
	DrawTexture(sprite->GetTexture(), 0, 0, WHITE);
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
	::DrawText(Text.c_str(), PosX, PosY, FontSize, WHITE);
}

void WindowRaylib::EndDraw()
{	
	EndDrawing();
}

void WindowRaylib::DestroyWindow()
{
	CloseWindow();
}
