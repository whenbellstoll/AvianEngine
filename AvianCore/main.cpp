#include "globals.h"

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

    FrameElem duckSprite = FrameElem("Assets/duck.bmp");
    FrameElem breadSprite = FrameElem("Assets/bread.bmp");

    printf("Allocating instances\n");

    Sprite* duckInst1 = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "duckInst");
    duckInst1->fe = &duckSprite;

    // draw person on top (small depth)
    duckInst1->ZOrder(1);
    duckInst1->MapPositionX(-0.5f);
    duckInst1->MapPositionY(-0.5f);
    duckInst1->ScaleX(0.007f);
    duckInst1->ScaleY(0.007f);

    Sprite* breadInst[5];
    
    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Sprite*)MEMPACK_AllocMem(&global.ramPack, sizeof(Sprite), "breadInst");
        breadInst[i]->fe = &breadSprite;

        // draw breads on bottom (larger depth)
        breadInst[i]->ZOrder(2); 
        breadInst[i]->MapPositionX(0.5f);
        breadInst[i]->MapPositionY( -0.5f + 0.2f * i );
        breadInst[i]->ScaleX(0.01f);
        breadInst[i]->ScaleY(0.01f);
    }

    // timer variables
    clock_t start;
    clock_t end;

    // initialize time
    start = clock();


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

        // Determine Tap and Release
        Input_ProcessState();

        // input
        // -----
        if (Input_KeyHold('A'))
            duckInst1->MapPositionX( duckInst1->MapPositionX() - elapsedTime );

        if (Input_KeyHold('D'))
            duckInst1->MapPositionX(duckInst1->MapPositionX() + elapsedTime);

        if (Input_KeyHold('W'))
            duckInst1->MapPositionY(duckInst1->MapPositionY() + elapsedTime);

        if (Input_KeyHold('S'))
            duckInst1->MapPositionY(duckInst1->MapPositionY() - elapsedTime);

        // Just for a test
        if (Input_KeyTap('T')) printf("Tap T\n");
        if (Input_KeyHold('Y')) printf("Hold Y\n");
        if (Input_KeyRelease('U')) printf("Release U\n");

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        duckInst1->DisplaySprite();

        for (int i = 0; i < 5; i++)
        {
            breadInst[i]->DisplaySprite();
        }

        // update swapchain
        glfwSwapBuffers(global.window);
    }

    // erase all allocated data
    MEMPACK_Clean(&global.ramPack);

    // erase resources
    delete mempackRamData;
    mempackRamData = nullptr;

    CleanOpenGL();

    // end program
    return 0;
}