#include "globals.h"

SpriteElem SpriteList[MAXACTORS];
struct Global global;



int main()
{
    printf("Globals: %d bytes\n", sizeof(global));

    // this should be the one and only "malloc"
    void* mempackRamData = malloc(ramSize);

    // initialize mempack for RAM
    MEMPACK_Init(&global.ramPack, mempackRamData, ramSize, "ram");

    // create a window, create context,
    // create GPU Mempacks, etc
    InitOpenGL();

    SpriteList[0] = *(SpriteElem *)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteElem), "duckInst");

    SpriteList[0].TotalAnimations = 2;
    SpriteList[0].Animations = new AnimationElem[2];

    FrameElem duckFrame = FrameElem("Assets/duck.bmp");
    duckFrame.Delay = 6;
    duckFrame.CurrentFrameTime = 6;
    FrameElem duckWTwoFrame = FrameElem("Assets/duckw2.bmp");
    duckWTwoFrame.Delay = 6;
    duckWTwoFrame.CurrentFrameTime = 6;
    FrameElem duckWThreeFrame = FrameElem("Assets/duckw3.bmp");
    duckWThreeFrame.Delay = 6;
    duckWThreeFrame.CurrentFrameTime = 6;
    FrameElem duckWFourFrame = FrameElem("Assets/duckw4.bmp");
    duckWFourFrame.Delay = 6;
    duckWFourFrame.CurrentFrameTime = 6;
    FrameElem duckWFiveFrame = FrameElem("Assets/duckw5.bmp");
    duckWFiveFrame.Delay = 6;
    duckWFiveFrame.CurrentFrameTime = 6;
    FrameElem duckWSixFrame = FrameElem("Assets/duckw6.bmp");
    duckWSixFrame.Delay = 6;
    duckWSixFrame.CurrentFrameTime = 6;

    AnimationElem duckIdle = AnimationElem();
    duckIdle.TotalFrames = 1;
    duckIdle.Frames = &duckFrame;

    AnimationElem duckWalk = AnimationElem();
    duckWalk.TotalFrames = 6;
    FrameElem walkFrames[6] = { duckFrame, duckWTwoFrame, duckWThreeFrame, duckWFourFrame, duckWFiveFrame, duckWSixFrame };
    duckWalk.Frames = &walkFrames[0];

    SpriteElem duckSprite = SpriteElem();
    duckSprite.TotalAnimations = 2;
    AnimationElem duckAnimation[2] = { duckIdle, duckWalk };
    duckSprite.Animations = &duckAnimation[0];

    FrameElem breadFrame = FrameElem("Assets/bread.bmp");
    breadFrame.Delay = 50;
    breadFrame.CurrentFrameTime = 50;

    AnimationElem breadAni = AnimationElem();
    breadAni.TotalFrames = 1;
    breadAni.Frames = &breadFrame;

    SpriteElem breadSprite = SpriteElem();
    breadSprite.TotalAnimations = 1;
    breadSprite.Animations = &breadAni;

    printf("Allocating instances\n");

    Sprite* duckInst1 = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "duckInst");
    duckInst1->se = &duckSprite;


    glfwGetWindowSize(global.window, &global.width, &global.height);
    // draw person on top (small depth)
    duckInst1->ZOrder(1);
    duckInst1->MapPositionX(-0.5f);
    duckInst1->MapPositionY(-0.5f);
    duckInst1->ScaleX( 2 / (float)global.width );
    duckInst1->ScaleY( 2 / (float)global.height ); 

    Sprite* breadInst[5];
    
    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "breadInst");
        breadInst[i]->se = &breadSprite;

        // draw breads on bottom (larger depth)
        breadInst[i]->ZOrder(2); 
        breadInst[i]->MapPositionX(0.5f);
        breadInst[i]->MapPositionY( -0.5f + 0.2f * i );
        breadInst[i]->ScaleX(2 / (float)global.width);
        breadInst[i]->ScaleY(2 / (float)global.height);
    }

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
    
        // input
        // -----
        if (pKeyboard->IsPressed('A') || pKeyboard->IsPressed(AK_LEFT))
            duckInst1->MapPositionX( duckInst1->MapPositionX() - elapsedTime );

        if (pKeyboard->IsPressed('D') || pKeyboard->IsPressed(AK_RIGHT))
            duckInst1->MapPositionX(duckInst1->MapPositionX() + elapsedTime);

        if (pKeyboard->IsPressed('W') || pKeyboard->IsPressed(AK_UP))
            duckInst1->MapPositionY(duckInst1->MapPositionY() + elapsedTime);

        if (pKeyboard->IsPressed('S') || pKeyboard->IsPressed(AK_DOWN) )
            duckInst1->MapPositionY(duckInst1->MapPositionY() - elapsedTime);

        // Just for a test
        if (pKeyboard->IsTriggered('T')) printf("Tap T\n");
        if (pKeyboard->IsPressed('Y')) printf("Hold Y\n");
        //if (pKeyboard->Any()) printf("Key pressed: \n"); // Prints constantly, only uncomment for demo 

        //printf("\n BB bread: %i , %i , %i , %i ", breadInst[0]->fe->BBox.left, breadInst[0]->fe->BBox.top, breadInst[0]->fe->BBox.right, breadInst[0]->fe->BBox.bottom);
        //printf("\n BB Duck: %i , %i , %i , %i ", duckInst1->fe->BBox.left, duckInst1->fe->BBox.top, duckInst1->fe->BBox.right, duckInst1->fe->BBox.bottom);
        //printf("\n Position Bread: %f , %f ", breadInst[0]->MapPositionX(), breadInst[0]->MapPositionY() );
        //printf("\n Position Duck: %f , %f ", duckInst1->MapPositionX(), duckInst1->MapPositionY());



        //if (IntersectRectangles1(duckInst1->fe->BBox, breadInst[0]->fe->BBox))
       // {
       //     printf("\n Collision between Duck and bread has been confirmed.");
       // }

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        duckInst1->dt = elapsedTime;
        duckInst1->DisplaySprite();

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

    // end program
    return 0;
}