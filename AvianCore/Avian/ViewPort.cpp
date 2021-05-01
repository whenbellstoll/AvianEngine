#include "../globals.h"

ViewPort::ViewPort(float wW, float wH, float worldX, float worldY, float width, float heigth)
{
    worldWidth = wW;
    worldHeight = wH;
    maxViewPortWorldXPos = worldX;
    maxViewPortWorldYPos = worldY;
	rect.top = 0;
	rect.left = 0;
	rect.right = width;
	rect.bottom = heigth;
	viewPort = rect;
	viewPort1 = rect;
}

float ViewPort::WorldWidth()
{
    return worldWidth;
}

float ViewPort::WorldHeight()
{
    return worldHeight;
}

void ViewPort::WorldWidth(float f)
{
	worldWidth = f;
}

void ViewPort::WorldHeight(float f)
{
	worldHeight = f;
}

void ViewPort::ViewPortWidth(float f)
{
	rect.right = f;

}

void ViewPort::ViewPortHeight(float f)
{
	rect.bottom = f;
}

float ViewPort::Width()
{
    return rect.right;
}

float ViewPort::Height()
{
    return rect.bottom;
}

float ViewPort::WorldXPos()
{
    return viewPort.left;
}

float ViewPort::WorldYPos()
{
    return viewPort.top;
}

float ViewPort::MaxViewPortWorldXPos()
{
    return maxViewPortWorldXPos;
}

float ViewPort::MaxViewPortWorldYPos()
{
	return maxViewPortWorldYPos;
}

void ViewPort::WorldXPos(float f)
{
	viewPort.left = f;
	viewPort.right = viewPort.left + Width();
	
	glViewport(viewPort.left, viewPort.top, global.width, global.height);
}

void ViewPort::WorldYPos(float f)
{
	viewPort.top = f;
	viewPort.bottom = viewPort.top + Height();
}

float ViewPort::WorldRightPos()
{
    return viewPort.right;
}

float ViewPort::WorldBottomPos()
{
    return viewPort.bottom;
}

FRECT ViewPort::WorldRect()
{
    return viewPort;
}

FRECT ViewPort::IntWorldRect()
{
    return rect;
}

FRECT ViewPort::Rect()
{
    return rect;
}

const DeltaScroll& ViewPort::Scroll(float dx, float dy)
{
    // TODO: insert return statement here
	return DeltaScroll();
}

const DeltaScroll& ViewPort::CurrentDeltaScroll()
{
    // TODO: insert return statement here
	return DeltaScroll();
}

void ViewPort::ViewPortScrollingBB(float viewPortX, float viewPortY, float width, float heigth)
{
    viewPortScrollingBB.top = viewPortY;
    viewPortScrollingBB.left = viewPortX;
    viewPortScrollingBB.bottom = viewPortY + heigth;
    viewPortScrollingBB.right = viewPortX + width;


}

float ViewPort::BBWidth()
{
    return viewPortScrollingBB.right - viewPortScrollingBB.left;
}

float ViewPort::BBHeigth()
{
    return viewPortScrollingBB.bottom - viewPortScrollingBB.top;
}

float ViewPort::BBWorldXPos()
{
    return viewPort.left + viewPortScrollingBB.left;

}

float ViewPort::BBWorldYPos()
{
    return viewPort.top + viewPortScrollingBB.top;

}

float ViewPort::BBWorldRightPos()
{
    return viewPort.left + viewPortScrollingBB.right;

}

float ViewPort::BBWorldBottomPos()
{
    return viewPort.top + viewPortScrollingBB.bottom;
}

FRECT ViewPort::BBWorldRect()
{
    return FRECT();
}

float ViewPort::BBViewPortXPos()
{
    return viewPortScrollingBB.left;
}

float ViewPort::BBViewPortYPos()
{
    return viewPortScrollingBB.top;
}

float ViewPort::BBViewPortRightPos()
{
    return viewPortScrollingBB.right;
}

float ViewPort::BBViewPortBottomPos()
{
    return viewPortScrollingBB.bottom;
}

FRECT ViewPort::BBViewPortRect()
{
    return FRECT();
}

float ViewPort::MaxInflateBBRight()
{
    return maxInflateBBRight;
}

float ViewPort::MaxInflateBBLeft()
{
    return maxInflateBBLeft;
}

float ViewPort::MaxInflateBBTop()
{
    return maxInflateBBTop;
}

float ViewPort::MaxInflateBBBottom()
{
    return maxInflateBBBottom;
}

void ViewPort::MaxInflateBBRight(float f)
{
    maxInflateBBRight = f;
}

void ViewPort::MaxInflateBBLeft(float f)
{
    maxInflateBBLeft = f;
}

void ViewPort::MaxInflateBBTop(float f)
{
    maxInflateBBTop = f;
}

void ViewPort::MaxInflateBBBottom(float f)
{
    maxInflateBBBottom = f;
}

float ViewPort::InflateBBRight(float f)
{
    return 0.0f;
}

float ViewPort::InflateBBLeft(float)
{
    return 0.0f;
}

float ViewPort::InflateBBTop(float)
{
    return 0.0f;
}

float ViewPort::InflateBBBottom(float)
{
    return 0.0f;
}

FRECT ViewPort::InitialBBClone()
{
    return FRECT();
}

void ViewPort::RestoreBB()
{
}

void ViewPort::DisplayBB()
{
}

DeltaScroll ViewPort::Offset(float x, float y, bool b)
{
    return DeltaScroll();
}

void ViewPort::OffsetVPSBB(float x, float y)
{
}

void ViewPort::Save(File&)
{
}

void ViewPort::Load(File&)
{
}

DYNCREATEIMP(ViewPort);
