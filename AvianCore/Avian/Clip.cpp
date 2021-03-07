#include "Clip.h"

bool CSLineOnLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    // calculate the distance to intersection point
    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    // if uA and uB are between 0-1, lines are colliding
    return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}

bool CSLineClipping(float flinex, float fliney, float llinex, float lliney, float topX, float topY, float bottomX, float bottomY)
{
    bool left = CSLineOnLine(flinex, fliney, llinex, lliney, topX, topY, topX, bottomY); // Are we colliding with the left side of the box?
    bool right = CSLineOnLine(flinex, fliney, llinex, lliney, bottomX, topY, bottomX, bottomY); // right?
    bool top = CSLineOnLine(flinex, fliney, llinex, lliney, topX, topY, bottomX, topY); // top?
    bool bottom = CSLineOnLine(flinex, fliney, llinex, lliney, topX, bottomY, bottomX, bottomY); // bottom?

    return(left || right || top || bottom);
}

outcode CompOutCode(float px, float py, float topX, float topY, float bottomX, float bottomY)
{
    if (py < topY) // is the point above?
    {
        return TOPC;
    }
    if (py > bottomY) // below?
    {
        return BOTTOMC;
    }
    if (px > bottomX) // right?
    {
        return RIGHTC;
    }
    if (px < topX) // left?
    {
        return LEFTC;
    }
    return 0; // colliding = 0
}

bool CSCircleClipping(float cx, float cy, float radius, float topX, float topY, float bottomX, float bottomY)
{
    // temporary variables to set edges for testing
    float testX = cx;
    float testY = cy;

    // which edge is closest?
    if (cx < topX)         testX = topX;      // test left edge
    else if (cx > bottomX) testX = bottomX;   // right edge
    if (cy < topY)         testY = topY;      // top edge
    else if (cy > bottomY) testY = bottomY;   // bottom edge

    // get distance from closest edges
    float distX = cx - testX;
    float distY = cy - testY;
    float distance = (distX * distX) + (distY * distY);

    // if the distance is less than the radius, collision!
    return (distance <= (radius * radius));
}

