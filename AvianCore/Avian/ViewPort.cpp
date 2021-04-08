#include "ViewPort.h"

ViewPort::ViewPort(float wW, float wH, float worldX, float worldY, float width, float heigth)
{
    worldWidth = wW;
    worldHeight = wH;
    maxViewPortWorldXPos = worldX;
    maxViewPortWorldYPos = worldY;
    
}

float ViewPort::WorldWidth()
{
    return 0.0f;
}

float ViewPort::WorldHeight()
{
    return 0.0f;
}

void ViewPort::WorldWidth(float)
{
}

void ViewPort::WorldHeight(float)
{
}

void ViewPort::ViewPortWidth(float)
{
}

void ViewPort::ViewPortHeight(float)
{
}

float ViewPort::Width()
{
    return 0.0f;
}

float ViewPort::Height()
{
    return 0.0f;
}

float ViewPort::WorldXPos()
{
    return 0.0f;
}

float ViewPort::WorldYPos()
{
    return 0.0f;
}

float ViewPort::MaxViewPortWorldXPos()
{
    return 0.0f;
}

float ViewPort::MaxViewPortWorldYPos()
{
    return 0.0f;
}

void ViewPort::WorldXPos(float)
{
}

void ViewPort::WorldYPos(float)
{
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
