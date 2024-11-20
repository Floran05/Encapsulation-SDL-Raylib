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

void ControllerSDL::AddKeyToListOfPressedKeys(int Key)
{
    pressedKeys.insert(Key);
}

void ControllerSDL::RemoveKeyFromListOfPressedKeys(int Key)
{
    const std::set<int>::iterator target = pressedKeys.find(Key);
    if (target != pressedKeys.end())
    {
        pressedKeys.erase(target);
    }
}

void ControllerSDL::ResetPressedKeys()
{
    pressedKeys.clear();

}
