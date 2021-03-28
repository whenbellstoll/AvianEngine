// Behavior Demo
#include "../globals.h"

void MoveSprite(Sprite* This)
{
    float distance = 0.01f;
    if (pKeyboard->IsPressed('A') || pKeyboard->IsPressed(AK_LEFT))
    {
        This->MapPositionX(This->MapPositionX() - distance);
        This->Animation(1);
        
        // This code needs to go into FrameElem update if( hFlip )
        if (This->ScaleX() != (2.0f / global.width))
        {
            This->ScaleX(2.0f / global.width);
            This->MapPositionX(This->MapPositionX() - (37 * (2.0f / global.width))); // 37 == SpriteList[0].Animation[2].Frames[x].width
        }
    }
    if (pKeyboard->IsPressed('D') || pKeyboard->IsPressed(AK_RIGHT))
    {
        This->MapPositionX(This->MapPositionX() + distance);
        This->Animation(1);
        
        if (This->ScaleX() != (-2.0f / global.width))
        {
            This->ScaleX(-2.0f / global.width);
            This->MapPositionX(This->MapPositionX() + (37 * (2.0f / global.width))); // 37 == SpriteList[0].Animation[2].Frames[x].width
        }
    }
    if (pKeyboard->IsPressed('W') || pKeyboard->IsPressed(AK_UP))
    {
        This->MapPositionY(This->MapPositionY() + distance);
        
    }
    if (pKeyboard->IsPressed('S') || pKeyboard->IsPressed(AK_DOWN))
    {
        This->MapPositionY(This->MapPositionY() - distance);
    }

    if (pKeyboard->Nothing())
    {
        if (This->Animation() == 1)
        {
            This->Animation(0);
        }
        else if(This->Animation() == 2 )
        {
            This->Animation(3);
        }
    }
}

//void CollectBread(Sprite* This)
