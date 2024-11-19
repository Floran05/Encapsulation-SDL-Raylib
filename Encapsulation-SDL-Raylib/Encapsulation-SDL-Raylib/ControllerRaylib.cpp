#include "ControllerRaylib.h"
#include "raylib.h"
bool ControllerRaylib::IsKeyDown(int Key)
{
	return ::IsKeyDown(Key);
}
