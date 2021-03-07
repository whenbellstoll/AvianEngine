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

    SpriteStruct* duckSprite = Sprite_Init("Assets/duck.bmp");
    SpriteStruct* breadSprite = Sprite_Init("Assets/bread.bmp");

    printf("Allocating instances\n");

    Instance* duckInst1 = (Instance*)MEMPACK_AllocMem(&global.ramPack, sizeof(Instance), "duckInst");
    duckInst1->sprite = duckSprite;

    // draw person on top (small depth)
    duckInst1->depth = 0.1f;
    duckInst1->posX = -0.5f;
    duckInst1->posY = -0.5f;
    duckInst1->scaleX = 0.007f;
    duckInst1->scaleY = 0.007f;

    Instance* breadInst[5];
    
    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Instance*)MEMPACK_AllocMem(&global.ramPack, sizeof(Instance), "breadInst");
        breadInst[i]->sprite = breadSprite;

        // draw breads on bottom (larger depth)
        breadInst[i]->depth = 0.2f; 
        breadInst[i]->posX = 0.5f;
        breadInst[i]->posY = -0.5f + 0.2f * i;
        breadInst[i]->scaleX = 0.01f;
        breadInst[i]->scaleY = 0.01f;
    }

    // timer variables
    clock_t start;
    clock_t end;

    // initialize time
    start = clock();


    // render loop
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
            duckInst1->posX -= elapsedTime;

        if (Input_KeyHold('D'))
            duckInst1->posX += elapsedTime;

        if (Input_KeyHold('W'))
            duckInst1->posY += elapsedTime;

        if (Input_KeyHold('S'))
            duckInst1->posY -= elapsedTime;

        // Just for a test
        if (Input_KeyTap('T')) printf("Tap T\n");
        if (Input_KeyHold('Y')) printf("Hold Y\n");
        if (Input_KeyRelease('U')) printf("Release U\n");

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Instance_Draw(duckInst1);

        for (int i = 0; i < 5; i++)
        {
            Instance_Draw(breadInst[i]);
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