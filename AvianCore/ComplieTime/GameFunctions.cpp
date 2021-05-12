// Behavior Demo
#include "../globals.h"

void MoveSprite(Sprite* This)
{
    float distance = 0.01f;
	int x = 0;
	int y = 0;
    if (pKeyboard->IsPressed('A') || pKeyboard->IsPressed(AK_LEFT) || pGamepadOne->GetAxis(0) < -0.5f )
    {
        x = -1;
        This->Animation(1);
        
        // This code needs to go into FrameElem update if( hFlip )
        if (This->ScaleX() != (2.0f / global.width))
        {
            This->ScaleX(2.0f / global.width);
            This->MapPositionX(This->MapPositionX() - (37 * (2.0f / global.width))); // 37 == SpriteList[0].Animation[2].Frames[x].width
        }
    }
    if (pKeyboard->IsPressed('D') || pKeyboard->IsPressed(AK_RIGHT) || pGamepadOne->GetAxis(0) > 0.5f )
    {
		x = 1;
        This->Animation(1);
        
        if (This->ScaleX() != (-2.0f / global.width))
        {
            This->ScaleX(-2.0f / global.width);
            This->MapPositionX(This->MapPositionX() + (37 * (2.0f / global.width))); // 37 == SpriteList[0].Animation[2].Frames[x].width
        }
    }
    if (pKeyboard->IsPressed('W') || pKeyboard->IsPressed(AK_UP) || pGamepadOne->GetAxis(1) > 0.5f)
    {
		y = 1;
        
    }
    if (pKeyboard->IsPressed('S') || pKeyboard->IsPressed(AK_DOWN) || pGamepadOne->GetAxis(1) < -0.5f )
    {
		y = -1;
    }

    if (pKeyboard->Nothing() && pGamepadOne->GetAxis(0) < 0.5f && pGamepadOne->GetAxis(0) > -0.5f )
    {
        
        This->Animation(0);
        
    }
	This->VectorDirection(x, y);
	//printf("\n Collision between Duck and bread has been confirmed. Positions: %f , %f", This->DirectionX(), This->DirectionY() );
}

void BreadCollisionWithSprite(Sprite* This)
{
    for (int i = 0; i < myGame->currentLevel->spriteList.NumberOfElements(); i++)
    {
        Sprite* s = (Sprite*)myGame->currentLevel->spriteList[i];
        if (s->ActorIndex() == 0)
        {
            if (This->CheckSpriteCollision(s))
            {
                This->Visible(false);
            }
        }
    }
}

//void CollectBread(Sprite* This)
