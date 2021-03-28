﻿#include "globals.h"
// Memory Leaks
#include <stdlib.h>
#include <crtdbg.h>

void** FArray;
int maxFIndex;

struct Global global;

//void (*f)(void*) = (void(*)(void*))MoveSprite;

int main()
{
    printf("Globals: %d bytes\n", sizeof(global));

    // these should be the only "malloc" calls
    void* mempackRamData = malloc(ramSize);
    void* levelpackRamData = malloc(levelSize);
    
    // initialize mempack for RAM
    MEMPACK_Init(&global.levelPack, levelpackRamData, levelSize, "levelMemory");
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
    glfwGetWindowSize(global.window, &global.width, &global.height);

    LoadAnimation();

    GameNode* g1 = new GameNode();//(GameNode*)MEMPACK_AllocMem(&global.ramPack, sizeof(GameNode), "Level 1");
    g1->spriteList.Clear();
    g1->spriteList.Resize(10);
    g1->mapList.Clear();
    g1->mapList.Resize(10);
    g1->Id(1);
    g1->Name("Level_1");
    g1->gameNodeLevelFunction = Init_Level_1;
    g1->transitionFunction = Exit_Level_1;
    g1->endLevelFunction = End_Level_1;
    global.currentLevel = g1;
    (*global.currentLevel->gameNodeLevelFunction)(global.currentLevel);

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

        // Just for a test
        if (pKeyboard->IsTriggered('T')) printf("Tap T\n");
        if (pKeyboard->IsPressed('Y')) printf("Hold Y\n");
        //if (pKeyboard->Any()) printf("Key pressed: \n"); // Prints constantly, only uncomment for demo 

        //
        //
        //printf("\n Position Bread: %f , %f ", breadInst[0]->MapPositionX(), breadInst[0]->MapPositionY() );
        //printf("\n Position Duck: %f , %f ", duckInst1->MapPositionX(), duckInst1->MapPositionY());


        // Calculate Rectangle Positions for collision
        /*Rect duckBox = SpriteList[duckInst1->ActorIndex()].Animations[duckInst1->Animation()].Frames[duckInst1->Frame()].BBox;
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
        }*/

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //mainMap->DisplayMap();
        /*mainMap->DisplayMap();

        duckInst1->dt = elapsedTime;
        duckInst1->UpdateSprite();

        for (int i = 0; i < 5; i++)
        {
            breadInst[i]->dt = elapsedTime;
            breadInst[i]->DisplaySprite();
        }*/
        global.currentLevel->Execute(elapsedTime);
        //Map* m = static_cast<Map *>(global.currentLevel->mapList[0]);
        //m->DisplayMap();

        if (pKeyboard->IsPressed(AK_ESCAPE)) // Close the program
        {
            glfwSetWindowShouldClose(global.window, GLFW_TRUE);
        }

        // update swapchain
        glfwSwapBuffers(global.window);
    }

    global.currentLevel->transitionFunction(global.currentLevel);
    delete global.currentLevel;
    // erase all allocated data
    MEMPACK_Clean(&global.ramPack);
    // erase global resources
    free(mempackRamData);
    mempackRamData = nullptr;

    // erase level resources
    free(levelpackRamData);
    levelpackRamData = nullptr;

    CleanOpenGL();
    _CrtDumpMemoryLeaks();

    // end program
    return 0;
}