#include "WindowRaylib.h"
#include <iostream>

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
