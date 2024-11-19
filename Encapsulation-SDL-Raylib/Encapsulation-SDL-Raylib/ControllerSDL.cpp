#include "ControllerSDL.h"

ControllerSDL::ControllerSDL()
{
    pressedKeys.clear();
}

ControllerSDL::~ControllerSDL()
{
}

bool ControllerSDL::IsKeyDown(int Key)
{
    return pressedKeys.find(Key) != pressedKeys.end();
}

void ControllerSDL::AddKeyToListOfPressedKey(int Key)
{
    pressedKeys.insert(Key);
}

void ControllerSDL::ResetPressedKeys()
{
    pressedKeys.clear();

}
