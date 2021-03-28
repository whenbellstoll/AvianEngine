#include "../globals.h"

SpriteElem SpriteList[MAXACTORS];

void LoadAnimation()
{
    SpriteList[0] = *(SpriteElem*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "duckSpriteElem");

    SpriteList[0].TotalAnimations = 4;
    SpriteList[0].Animations = new AnimationElem[4];

    SpriteList[0].Animations[0].TotalFrames = 1;
    SpriteList[0].Animations[0].ConnectTo = 0;
    SpriteList[0].Animations[0].Frames = new FrameElem[1];

    SpriteList[0].Animations[0].Frames[0] = FrameElem("Assets/duck.bmp");
    SpriteList[0].Animations[0].Frames[0].Delay = 6;
    SpriteList[0].Animations[0].Frames[0].Transparency = RGB(255, 255, 255);



    SpriteList[0].Animations[1].TotalFrames = 6;
    SpriteList[0].Animations[1].ConnectTo = 0;
    SpriteList[0].Animations[1].Frames = new FrameElem[6];

    SpriteList[0].Animations[1].Frames[0] = FrameElem("Assets/duck.bmp");
    SpriteList[0].Animations[1].Frames[0].Delay = 6;
    SpriteList[0].Animations[1].Frames[0].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[1] = FrameElem("Assets/duckw2.bmp");
    SpriteList[0].Animations[1].Frames[1].Delay = 6;
    SpriteList[0].Animations[1].Frames[1].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[2] = FrameElem("Assets/duckw3.bmp");
    SpriteList[0].Animations[1].Frames[2].Delay = 6;
    SpriteList[0].Animations[1].Frames[2].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[3] = FrameElem("Assets/duckw4.bmp");
    SpriteList[0].Animations[1].Frames[3].Delay = 6;
    SpriteList[0].Animations[1].Frames[3].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[4] = FrameElem("Assets/duckw5.bmp");
    SpriteList[0].Animations[1].Frames[4].Delay = 6;
    SpriteList[0].Animations[1].Frames[4].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[5] = FrameElem("Assets/duckw6.bmp");
    SpriteList[0].Animations[1].Frames[5].Delay = 6;
    SpriteList[0].Animations[1].Frames[5].Transparency = RGB(255, 255, 255);
    
    // Do this for some reason ?? texture appears really big for no discernable reason otherwise
    SpriteList[0].Animations[0].Frames[0] = SpriteList[0].Animations[1].Frames[0];
    
    SpriteList[0].Animations[2].TotalFrames = 6;
    SpriteList[0].Animations[2].ConnectTo = 0;
    SpriteList[0].Animations[2].Frames = new FrameElem[6];
                             
    SpriteList[0].Animations[2].Frames[0] = FrameElem("Assets/duckr.bmp");
    SpriteList[0].Animations[2].Frames[0].Delay = 6;
    SpriteList[0].Animations[2].Frames[0].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[2].Frames[1] = FrameElem("Assets/duckwr2.bmp");
    SpriteList[0].Animations[2].Frames[1].Delay = 6;
    SpriteList[0].Animations[2].Frames[1].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[2].Frames[2] = FrameElem("Assets/duckwr3.bmp");
    SpriteList[0].Animations[2].Frames[2].Delay = 6;
    SpriteList[0].Animations[2].Frames[2].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[2].Frames[3] = FrameElem("Assets/duckwr4.bmp");
    SpriteList[0].Animations[2].Frames[3].Delay = 6;
    SpriteList[0].Animations[2].Frames[3].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[2].Frames[4] = FrameElem("Assets/duckwr5.bmp");
    SpriteList[0].Animations[2].Frames[4].Delay = 6;
    SpriteList[0].Animations[2].Frames[4].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[2].Frames[5] = FrameElem("Assets/duckwr6.bmp");
    SpriteList[0].Animations[2].Frames[5].Delay = 6;
    SpriteList[0].Animations[2].Frames[5].Transparency = RGB(255, 255, 255);

    SpriteList[0].Animations[3].TotalFrames = 1;
    SpriteList[0].Animations[3].ConnectTo = 0;
    SpriteList[0].Animations[3].Frames = new FrameElem[1];
                             
    SpriteList[0].Animations[3].Frames[0] = SpriteList[0].Animations[2].Frames[0];
    SpriteList[0].Animations[3].Frames[0].Delay = 6;
    SpriteList[0].Animations[3].Frames[0].Transparency = RGB(255, 255, 255);

    SpriteList[1] = *(SpriteElem*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "breadSpriteElem");

    SpriteList[1].TotalAnimations = 1;
    SpriteList[1].Animations = new AnimationElem[1];

    SpriteList[1].Animations[0].TotalFrames = 1;
    SpriteList[1].Animations[0].ConnectTo = 0;
    SpriteList[1].Animations[0].Frames = new FrameElem[1];

    SpriteList[1].Animations[0].Frames[0] = FrameElem("Assets/bread.bmp");
    SpriteList[1].Animations[0].Frames[0].Delay = 50;
    SpriteList[1].Animations[0].Frames[0].Transparency = RGB(255, 255, 255);

}
