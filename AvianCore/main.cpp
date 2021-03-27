#include "globals.h"
// Memory Leaks
#include <stdlib.h>
#include <crtdbg.h>

void** FArray;
int maxFIndex;
SpriteElem SpriteList[MAXACTORS];
struct Global global;

//void (*f)(void*) = (void(*)(void*))MoveSprite;

int main()
{
    printf("Globals: %d bytes\n", sizeof(global));

    // this should be the one and only "malloc"
    void* mempackRamData = malloc(ramSize);

    // initialize mempack for RAM
    MEMPACK_Init(&global.ramPack, mempackRamData, ramSize, "ram");
    
    maxFIndex = 0;
    // Allocate Memory for Function Array
    FArray = (void**)MEMPACK_AllocMem(&global.ramPack, sizeof(void*), "Function Array");
    // Add our behavior from GameFunctions.h to FArray
    FArray[0] = (void *)MoveSprite;
    


    // create a window, create context,
    // create GPU Mempacks, etc
    InitOpenGL();

    SpriteList[0] = *(SpriteElem *)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "duckSpriteElem");

    SpriteList[0].TotalAnimations = 2;
    SpriteList[0].Animations = new AnimationElem[2];

    SpriteList[0].Animations[0].TotalFrames = 1;
    SpriteList[0].Animations[0].ConnectTo = 0;
    SpriteList[0].Animations[0].Frames = new FrameElem[1];

    SpriteList[0].Animations[0].Frames[0] = FrameElem("Assets/duck.bmp");
    SpriteList[0].Animations[0].Frames[0].Delay = 6;
    SpriteList[0].Animations[0].Frames[0].Transparency = RGB(255,255,255);


 
    SpriteList[0].Animations[1].TotalFrames = 6;
    SpriteList[0].Animations[1].ConnectTo = 0;
    SpriteList[0].Animations[1].Frames = new FrameElem[6];

    SpriteList[0].Animations[1].Frames[0] = SpriteList[0].Animations[0].Frames[0];
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


    SpriteList[1] = *(SpriteElem*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "breadSpriteElem");

    SpriteList[1].TotalAnimations = 1;
    SpriteList[1].Animations = new AnimationElem[1];

    SpriteList[1].Animations[0].TotalFrames = 1;
    SpriteList[1].Animations[0].ConnectTo = 0;
    SpriteList[1].Animations[0].Frames = new FrameElem[1];

    SpriteList[1].Animations[0].Frames[0] = FrameElem("Assets/bread.bmp");
    SpriteList[1].Animations[0].Frames[0].Delay = 50;
    SpriteList[1].Animations[0].Frames[0].Transparency = RGB(255, 255, 255);

    printf("Allocating instances\n");

    Sprite* duckInst1 = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "duckInst");


    glfwGetWindowSize(global.window, &global.width, &global.height);
    // draw duck on top (small depth)
    duckInst1->ZOrder(1);
    duckInst1->MapPositionX(-0.5f);
    duckInst1->MapPositionY(-0.5f);
    duckInst1->ScaleX( 2 / (float)global.width );
    duckInst1->ScaleY( 2 / (float)global.height ); 
    duckInst1->ActorIndex(0);
    duckInst1->Animation(0);
    duckInst1->Frame(0);
    duckInst1->Delay(6);

    Sprite* breadInst[5];
    
    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "breadInst");

        // draw breads on bottom (larger depth)
        breadInst[i]->ZOrder(2); 
        breadInst[i]->MapPositionX(0.5f);
        breadInst[i]->MapPositionY( -0.5f + 0.2f * i );
        breadInst[i]->ScaleX(2 / (float)global.width);
        breadInst[i]->ScaleY(2 / (float)global.height);
        breadInst[i]->ActorIndex(1);
        breadInst[i]->Animation(0);
        breadInst[i]->Frame(0);
        breadInst[i]->Delay(50);

    }
    
    
    Behavior b = Behavior();
    duckInst1->behavior = &b;
    duckInst1->behavior->AddFunction(0, true);

    // Add Map
    //Map mM = Map("mainMap", "Assets/Maps/mainMap.bmp", Map::MapType::STANDARDMAP);
    Map* mainMap = (Map *)MEMPACK_AllocMem(&global.ramPack, sizeof(Map), "mainMap");
    mainMap->FileName("Assets/Maps/mainMap.bmp");
    mainMap->Name("mainMap");

    // timer variables
    clock_t start;
    clock_t end;

    // initialize time
    start = clock();

    // Testing Collision Segment
    bool collisionSegment = CSLineOnLine(0, 0, 1, 2, 2, 0, 0, 1);
    if (collisionSegment)
    {
        printf("\n Segment Collision Test passing. \n ");
    }
    // game loop
    // -----------
    int noCount = 0;
    while (!glfwWindowShouldClose(global.window))
    {
        // measure elapsed time per frame
        end = clock();
        float elapsedTime = (end - start) / 1000.0f;
        start = clock();

        // Update controller "hold" variable
        glfwPollEvents();

        // Determine Key States
        pKeyboard->ProcessKeys();
    
        // Behavior
        //(*f)(duckInst1);
        //(*(void (*)(void *))FArray[0])(duckInst1);
        // input
        // -----
        

        // Just for a test
        if (pKeyboard->IsTriggered('T')) printf("Tap T\n");
        if (pKeyboard->IsPressed('Y')) printf("Hold Y\n");
        //if (pKeyboard->Any()) printf("Key pressed: \n"); // Prints constantly, only uncomment for demo 

        //
        //
        //printf("\n Position Bread: %f , %f ", breadInst[0]->MapPositionX(), breadInst[0]->MapPositionY() );
        //printf("\n Position Duck: %f , %f ", duckInst1->MapPositionX(), duckInst1->MapPositionY());


        // Calculate Rectangle Positions for collision
        Rect duckBox = SpriteList[duckInst1->ActorIndex()].Animations[duckInst1->Animation()].Frames[duckInst1->Frame()].BBox;
        Rect breadBox = SpriteList[breadInst[0]->ActorIndex()].Animations[breadInst[0]->Animation()].Frames[breadInst[0]->Frame()].BBox;
        float duckrealSpaceX = (duckInst1->MapPositionX() + 1) * (global.width / 2);
        float duckrealSpaceY = (duckInst1->MapPositionY() - 1) * (global.height / 2) * -1;
        duckBox.left = duckrealSpaceX;
        duckBox.right = duckrealSpaceX + SpriteList[duckInst1->ActorIndex()].Animations[duckInst1->Animation()].Frames[duckInst1->Frame()].Width;
        duckBox.top = duckrealSpaceY;
        duckBox.bottom = duckrealSpaceY + SpriteList[duckInst1->ActorIndex()].Animations[duckInst1->Animation()].Frames[duckInst1->Frame()].Height;

        float breadrealSpaceX = (breadInst[0]->MapPositionX() + 1) * (global.width / 2);
        float breadrealSpaceY = (breadInst[0]->MapPositionY() - 1) * (global.height / 2) * -1;
        breadBox.left = breadrealSpaceX;
        breadBox.right = breadrealSpaceX + SpriteList[breadInst[0]->ActorIndex()].Animations[breadInst[0]->Animation()].Frames[breadInst[0]->Frame()].Width;
        breadBox.top = breadrealSpaceY;
        breadBox.bottom = breadrealSpaceY + SpriteList[breadInst[0]->ActorIndex()].Animations[breadInst[0]->Animation()].Frames[breadInst[0]->Frame()].Height;

        // printf("\n BB bread: %i , %i , %i , %i ", breadBox.left, breadBox.top, breadBox.right, breadBox.bottom);
        // printf("\n BB Duck: %i , %i , %i , %i ", duckBox.left, duckBox.top, duckBox.right, duckBox.bottom);
        if (IntersectRectangles1(duckBox, breadBox))
        {
            printf("\n Collision between Duck and bread has been confirmed. Positions: %i , %i , %i , %i", (int)duckrealSpaceX, (int)duckrealSpaceY, (int)breadrealSpaceX, (int)breadrealSpaceY);
        }

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //mainMap->DisplayMap();
        mainMap->DisplayMap();

        duckInst1->dt = elapsedTime;
        duckInst1->UpdateSprite();

        for (int i = 0; i < 5; i++)
        {
            breadInst[i]->dt = elapsedTime;
            breadInst[i]->DisplaySprite();
        }


        if (pKeyboard->IsPressed(AK_ESCAPE)) // Close the program
        {
            glfwSetWindowShouldClose(global.window, GLFW_TRUE);
        }
        // update swapchain
        glfwSwapBuffers(global.window);
    }

    // erase all allocated data
    MEMPACK_Clean(&global.ramPack);
    // erase resources
    free(mempackRamData);
    mempackRamData = nullptr;

    CleanOpenGL();
    _CrtDumpMemoryLeaks();

    // end program
    return 0;
}