#include "ViewPort.h"

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
}

void ViewPort::WorldYPos(float f)
{
	viewPort.top = f;
	viewPort.bottom = viewPort.top + Height();
}

float ViewPort::WorldRightPos()
{
    return 0.0f;
}

float ViewPort::WorldBottomPos()
{
    return 0.0f;
}

FRECT ViewPort::WorldRect()
{
    return FRECT();
}

FRECT ViewPort::IntWorldRect()
{
    return FRECT();
}

FRECT ViewPort::Rect()
{
    return FRECT();
}

const DeltaScroll& ViewPort::Scroll(float dx, float dy)
{
    // TODO: insert return statement here
}

const DeltaScroll& ViewPort::CurrentDeltaScroll()
{
    // TODO: insert return statement here
}

void ViewPort::ViewPortScrollingBB(float viewPortX, float viewPortY, float width, float heigth)
{
}

float ViewPort::BBWidth()
{
    return 0.0f;
}

float ViewPort::BBHeigth()
{
    return 0.0f;
}

float ViewPort::BBWorldXPos()
{
    return 0.0f;
}

float ViewPort::BBWorldYPos()
{
    return 0.0f;
}

float ViewPort::BBWorldRightPos()
{
    return 0.0f;
}

float ViewPort::BBWorldBottomPos()
{
    return 0.0f;
}

FRECT ViewPort::BBWorldRect()
{
    return FRECT();
}

float ViewPort::BBViewPortXPos()
{
    return 0.0f;
}

float ViewPort::BBViewPortYPos()
{
    return 0.0f;
}

float ViewPort::BBViewPortRightPos()
{
    return 0.0f;
}

float ViewPort::BBViewPortBottomPos()
{
    return 0.0f;
}

FRECT ViewPort::BBViewPortRect()
{
    return FRECT();
}

float ViewPort::MaxInflateBBRight()
{
    return 0.0f;
}

float ViewPort::MaxInflateBBLeft()
{
    return 0.0f;
}

float ViewPort::MaxInflateBBTop()
{
    return 0.0f;
}

float ViewPort::MaxInflateBBBottom()
{
    return 0.0f;
}

void ViewPort::MaxInflateBBRight(float)
{
}

void ViewPort::MaxInflateBBLeft(float)
{
}

void ViewPort::MaxInflateBBTop(float)
{
}

void ViewPort::MaxInflateBBBottom(float)
{
}

float ViewPort::InflateBBRight(float)
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

DeltaScroll ViewPort::Offset(float x, float y, bool)
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
