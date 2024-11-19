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

void WindowRaylib::DrawEntity(Entity* Entity)
{
	Vector2 Position;
	Position.x = Entity->GetPosition().x;
	Position.y = Entity->GetPosition().y;
	SpriteRaylib* sprite = dynamic_cast<SpriteRaylib*>(Entity->GetSprite());
	DrawTextureV(sprite->GetTexture(),Position,WHITE);
	
}

void WindowRaylib::ProcessEvents()
{
}

void WindowRaylib::BeginDraw()
{
	BeginDraw();
}

void WindowRaylib::EndDraw()
{	
	EndDraw();
}

void WindowRaylib::DestroyWindow()
{
	CloseWindow();
}
