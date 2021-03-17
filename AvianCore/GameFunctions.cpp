// Behavior Demo
#include "globals.h"

void MoveSprite(Sprite* This)
{
    float distance = 0.01f;
    if (pKeyboard->IsPressed('A') || pKeyboard->IsPressed(AK_LEFT))
    {
        This->MapPositionX(This->MapPositionX() - distance);
        This->Animation(1);
    }
    if (pKeyboard->IsPressed('D') || pKeyboard->IsPressed(AK_RIGHT))
    {
        This->MapPositionX(This->MapPositionX() + distance);
        This->Animation(1);
    }
    if (pKeyboard->IsPressed('W') || pKeyboard->IsPressed(AK_UP))
    {
        This->MapPositionY(This->MapPositionY() + distance);
        This->Animation(0);
    }
    if (pKeyboard->IsPressed('S') || pKeyboard->IsPressed(AK_DOWN))
    {
        This->MapPositionY(This->MapPositionY() - distance);
        This->Animation(0);
    }

    if (pKeyboard->Nothing())
    {
        This->Animation(0);
    }
}

//void CollectBread(Sprite* This)
