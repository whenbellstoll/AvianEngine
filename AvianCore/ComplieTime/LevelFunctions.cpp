#include "LevelFunctions.h"
#include "../globals.h"

void Init_Level_1(GameNode* gn)
{
    

    printf("Allocating instances\n");

    Sprite* duckInst1 = (Sprite*)MEMPACK_AllocMem(&global.levelPack, sizeof(Sprite), "duckInst");

    // draw duck on top (small depth)
    duckInst1->ZOrder(1);
    duckInst1->MapPositionX(-0.5f);
    duckInst1->MapPositionY(0.5f);
    duckInst1->ScaleX(2 / (float)global.width);
    duckInst1->ScaleY(2 / (float)global.height);
    duckInst1->ActorIndex(0);
    duckInst1->Animation(0);
    duckInst1->Frame(0);
    duckInst1->Delay(6);
	duckInst1->Speed(4.25f);
	duckInst1->VectorDirection(0, 0);
	duckInst1->Visible(true);
    duckInst1->behavior = new Behavior();
    duckInst1->behavior->AddFunction(0, true);
    gn->Add(duckInst1);

    Sprite* breadInst[5];

    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Sprite*)MEMPACK_AllocMem(&global.levelPack, sizeof(Sprite), "breadInst");

        // draw breads on bottom (larger depth)
        breadInst[i]->ZOrder(2);
        breadInst[i]->MapPositionX(0.5f);
        breadInst[i]->MapPositionY(-0.5f + 0.2f * i);
        breadInst[i]->ScaleX(2 / (float)global.width);
        breadInst[i]->ScaleY(2 / (float)global.height);
        breadInst[i]->ActorIndex(1);
        breadInst[i]->Animation(0);
        breadInst[i]->Frame(0);
        breadInst[i]->Delay(50);
		breadInst[i]->Speed(0);
		breadInst[i]->VectorDirection(0, 0);
		breadInst[i]->Visible(true);
        breadInst[i]->behavior = new Behavior();
        breadInst[i]->behavior->AddFunction(1, true);
        gn->Add(breadInst[i]);
    }


    

    // Add Map
    gn->AddMap("mainMap", "Assets/Maps/mainMap.bmp", Map::MapType::STANDARDMAP);
}

void Exit_Level_1(GameNode* gn)
{
	
}

void End_Level_1(GameNode* gn)
{
	for (int i = 0; i < gn->spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)gn->spriteList[i];
		delete s->behavior;
	}
    gn->mapList.Clear();
    gn->spriteList.Clear();
	gn->variableList.Clear();
	gn->soundList.Clear();
	gn->musicList.Clear();
	gn->particleSystemList.Clear();
    MEMPACK_Clean(&global.mappboPack);
    MEMPACK_Clean(&global.mapvboPack);
    MEMPACK_Clean(&global.levelPack);
}

void Init_Level_2(GameNode* gn)
{
    printf("Allocating instances\n");

    Sprite* duckInst1 = (Sprite*)MEMPACK_AllocMem(&global.levelPack, sizeof(Sprite), "duckInst");

    // draw duck on top (small depth)
    duckInst1->ZOrder(1);
    duckInst1->MapPositionX(-0.5f);
    duckInst1->MapPositionY(-0.5f);
    duckInst1->ScaleX(2 / (float)global.width);
    duckInst1->ScaleY(2 / (float)global.height);
    duckInst1->ActorIndex(0);
    duckInst1->Animation(0);
    duckInst1->Frame(0);
    duckInst1->Delay(6);
    duckInst1->Visible(true);
    //Behavior duckb = Behavior();
    duckInst1->behavior = new Behavior();
    duckInst1->behavior->AddFunction(0, true);
    gn->Add(duckInst1);

    Sprite* breadInst[5];

    for (int i = 0; i < 5; i++)
    {
        breadInst[i] = (Sprite*)MEMPACK_AllocMem(&global.levelPack, sizeof(Sprite), "breadInst");

        // draw breads on bottom (larger depth)
        breadInst[i]->ZOrder(2);
        breadInst[i]->MapPositionX(-0.5f + 0.2f * i );
        breadInst[i]->MapPositionY(0.5f );
        breadInst[i]->ScaleX( (-2) / (float)global.width);
        breadInst[i]->ScaleY( (2 * (i + 1) ) / (float)global.height);
        breadInst[i]->ActorIndex(1);
        breadInst[i]->Animation(0);
        breadInst[i]->Frame(0);
        breadInst[i]->Delay(50);
        breadInst[i]->Visible(true);
        breadInst[i]->behavior = new Behavior();
        gn->Add(breadInst[i]);
    }




    // Add Map
    gn->AddMap("mainMap", "Assets/Maps/twoMap.bmp", Map::MapType::STANDARDMAP);
}

void Exit_Level_2(GameNode* gn)
{
    
}

void End_Level_2(GameNode* gn)
{
	for (int i = 0; i < gn->spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)gn->spriteList[i];
		delete s->behavior;
	}
	gn->mapList.Clear();
	gn->spriteList.Clear();
	gn->variableList.Clear();
	gn->soundList.Clear();
	gn->musicList.Clear();
	gn->particleSystemList.Clear();
    MEMPACK_Clean(&global.mappboPack);
    MEMPACK_Clean(&global.mapvboPack);
    MEMPACK_Clean(&global.levelPack);
}
