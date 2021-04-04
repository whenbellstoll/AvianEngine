#include "../globals.h"

SpriteElem SpriteList[MAXACTORS];

void LoadAnimation()
{
    SpriteList[0] = *(SpriteElem*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "duckSpriteElem");

    SpriteList[0].TotalAnimations = 2;
    SpriteList[0].Animations = new AnimationElem[2];

    SpriteList[0].Animations[0].TotalFrames = 1;
    SpriteList[0].Animations[0].ConnectTo = 0;
    SpriteList[0].Animations[0].Frames = new FrameElem[1];

    SpriteList[0].Animations[0].Frames[0].IniFrame("Assets/duck.bmp");
    SpriteList[0].Animations[0].Frames[0].Delay = 6;
    SpriteList[0].Animations[0].Frames[0].Transparency = RGB(255, 255, 255);



    SpriteList[0].Animations[1].TotalFrames = 6;
    SpriteList[0].Animations[1].ConnectTo = 0;
    SpriteList[0].Animations[1].Frames = new FrameElem[6];

    SpriteList[0].Animations[1].Frames[0].IniFrame("Assets/duck.bmp");
    SpriteList[0].Animations[1].Frames[0].Delay = 6;
    SpriteList[0].Animations[1].Frames[0].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[1].IniFrame("Assets/duckw2.bmp");
    SpriteList[0].Animations[1].Frames[1].Delay = 6;
    SpriteList[0].Animations[1].Frames[1].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[2].IniFrame("Assets/duckw3.bmp");
    SpriteList[0].Animations[1].Frames[2].Delay = 6;
    SpriteList[0].Animations[1].Frames[2].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[3].IniFrame("Assets/duckw4.bmp");
    SpriteList[0].Animations[1].Frames[3].Delay = 6;
    SpriteList[0].Animations[1].Frames[3].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[4].IniFrame("Assets/duckw5.bmp");
    SpriteList[0].Animations[1].Frames[4].Delay = 6;
    SpriteList[0].Animations[1].Frames[4].Transparency = RGB(255, 255, 255);
    SpriteList[0].Animations[1].Frames[5].IniFrame("Assets/duckw6.bmp");
    SpriteList[0].Animations[1].Frames[5].Delay = 6;
    SpriteList[0].Animations[1].Frames[5].Transparency = RGB(255, 255, 255);
    
    // Do this for some reason ?? texture appears really big for no discernable reason otherwise
    SpriteList[0].Animations[0].Frames[0] = SpriteList[0].Animations[1].Frames[0];

    SpriteList[1] = *(SpriteElem*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "breadSpriteElem");

    SpriteList[1].TotalAnimations = 1;
    SpriteList[1].Animations = new AnimationElem[1];

    SpriteList[1].Animations[0].TotalFrames = 1;
    SpriteList[1].Animations[0].ConnectTo = 0;
    SpriteList[1].Animations[0].Frames = new FrameElem[1];

    SpriteList[1].Animations[0].Frames[0].IniFrame("Assets/bread.bmp");
    SpriteList[1].Animations[0].Frames[0].Delay = 50;
    SpriteList[1].Animations[0].Frames[0].Transparency = RGB(255, 255, 255);

}

void DeleteAnimations()
{
	/*for (int s = 0; s < MAXACTORS; s++) 
	{
		for (int a = 0; a < SpriteList[s].TotalAnimations; a++)
		{
			//for (int f = 0; f < SpriteList[s].Animations[a].TotalFrames; f++)
			//{
				delete SpriteList[s].Animations[a].Frames;
			//}
		}
	}*/
	//delete[] SpriteList[0].Animations[0].Frames;
	//delete[] SpriteList[0].Animations[1].Frames;
	//delete[] SpriteList[1].Animations[0].Frames;
	//SpriteList[0].Animations[0].~AnimationElem();
	//SpriteList[0].Animations[1].~AnimationElem();
	//SpriteList[1].Animations[0].~AnimationElem();
	//SpriteList[0].Animations = nullptr;
	delete[] SpriteList[0].Animations;
	delete[] SpriteList[1].Animations;
	//SpriteList[0].~SpriteElem();
	//SpriteList[1].~SpriteElem();
	delete SpriteList;
}