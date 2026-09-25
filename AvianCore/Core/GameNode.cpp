#include "../globals.h"
#include "GameNode.h"

GameNode::GameNode()
{
	spriteCount = 0;
	mapCount = 0;
	variableCount = 0;
	soundCount = 0;
	musicCount = 0;
	particleSystemCount = 0;
	currentFPS = 60.0f;
	
	
	
}

GameNode::~GameNode()
{
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)spriteList[i];
		delete s->behavior;
	}
	mapList.~Array();
	spriteList.~Array();
	variableList.~Array();
	soundList.~Array();
	musicList.~Array();
	particleSystemList.~Array();
}

void GameNode::Execute(float dt)
{
	// test
	//viewPort.WorldXPos(viewPort.WorldXPos() - 0.1);

	// Update objects
	// Maps
	for (int i = 0; i < mapList.NumberOfElements(); i++)
	{
		Map* m = (Map*)mapList[i];
		m->DisplayMap();
	}
	// Sprites
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)spriteList[i];
		s->dt = dt;
		s->UpdateSprite();
	}

	// ============================================================
	// VIEWPORT/CAMERA UPDATE - Follow first sprite (MVP)
	// ============================================================
	if (spriteList.NumberOfElements() > 0)
	{
		Sprite* player = (Sprite*)spriteList[0];

		// Center camera on player
		float targetWorldX = player->MapPositionX() - (viewPort.Width() / 2.0f);
		float targetWorldY = player->MapPositionY() - (viewPort.Height() / 2.0f);

		// Clamp to world bounds
		if (targetWorldX < 0.0f) targetWorldX = 0.0f;
		if (targetWorldY < 0.0f) targetWorldY = 0.0f;
		if (targetWorldX + viewPort.Width() > viewPort.WorldWidth())
			targetWorldX = viewPort.WorldWidth() - viewPort.Width();
		if (targetWorldY + viewPort.Height() > viewPort.WorldHeight())
			targetWorldY = viewPort.WorldHeight() - viewPort.Height();

		viewPort.WorldXPos(targetWorldX);
		viewPort.WorldYPos(targetWorldY);
	}

	// ============================================================
	// COLLISION DETECTION PHASE - Shape-Based Collision
	// ============================================================

	// Stage 1: Populate sprite collision shapes from current animation frames
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* sprite = (Sprite*)spriteList[i];
		sprite->UpdateOwnerCollisionData();
	}

	// Stage 2: Sprite vs Map collision (using shape-based detection)
	if (mapList.NumberOfElements() > 0)
	{
		Map* worldMap = (Map*)mapList[0];

		for (int i = 0; i < spriteList.NumberOfElements(); i++)
		{
			Sprite* sprite = (Sprite*)spriteList[i];
			if (!sprite->CheckCollisionWithMap()) continue;
			if (sprite->ownerCollisionData.NumberOfElements() == 0) continue;

			// Get sprite bounding box for collision query
			float spriteBboxLeft = sprite->MapPositionX() - sprite->Width() / 2.0f;
			float spriteBboxTop = sprite->MapPositionY() - sprite->Height() / 2.0f;
			float spriteBboxWidth = (float)sprite->Width();
			float spriteBboxHeight = (float)sprite->Height();

			// Query map for collision shapes near this sprite
			worldMap->GetCollisionDataInBounds(
				spriteBboxLeft, spriteBboxTop,
				spriteBboxWidth, spriteBboxHeight,
				sprite->mapCollisionData
			);

			// Test each sprite shape against each map shape
			bool hasCollision = false;
			for (int os = 0; os < sprite->ownerCollisionData.NumberOfElements() && !hasCollision; os++)
			{
				CollisionData* spriteShape = sprite->ownerCollisionData[os];

				for (int ms = 0; ms < sprite->mapCollisionData.NumberOfElements(); ms++)
				{
					CollisionData* mapShape = sprite->mapCollisionData[ms];

					// Use shape-based collision detection with proper type dispatch
					bool collision = false;

					if (spriteShape->Type() == ColSegment)
					{
						CollisionSegment* seg1 = (CollisionSegment*)spriteShape;
						if (mapShape->Type() == ColSegment)
						{
							CollisionSegment* seg2 = (CollisionSegment*)mapShape;
							collision = seg1->DetectCollision(seg2, 
								sprite->MapPositionX(), sprite->MapPositionY(),
								0.0f, 0.0f,
								sprite->TranslationX(), sprite->TranslationY(),
								sprite->Speed());
						}
						else if (mapShape->Type() == ColCircle)
						{
							CollisionCircle* circ2 = (CollisionCircle*)mapShape;
							collision = seg1->DetectCollision(circ2,
								sprite->MapPositionX(), sprite->MapPositionY(),
								0.0f, 0.0f,
								sprite->TranslationX(), sprite->TranslationY(),
								sprite->Speed());
						}
					}
					else if (spriteShape->Type() == ColCircle)
					{
						CollisionCircle* circ1 = (CollisionCircle*)spriteShape;
						if (mapShape->Type() == ColSegment)
						{
							CollisionSegment* seg2 = (CollisionSegment*)mapShape;
							collision = circ1->DetectCollision(seg2,
								sprite->MapPositionX(), sprite->MapPositionY(),
								0.0f, 0.0f,
								sprite->TranslationX(), sprite->TranslationY(),
								sprite->Speed());
						}
						else if (mapShape->Type() == ColCircle)
						{
							CollisionCircle* circ2 = (CollisionCircle*)mapShape;
							collision = circ1->DetectCollision(circ2,
								sprite->MapPositionX(), sprite->MapPositionY(),
								0.0f, 0.0f,
								sprite->TranslationX(), sprite->TranslationY(),
								sprite->Speed());
						}
					}

					if (collision)
					{
						hasCollision = true;
						break;
					}
				}
			}

			sprite->CollisionWithMap(hasCollision);
		}
	}

	// Stage 3: Sprite vs Sprite collision (using shape-based detection)
	// Clear collision records from previous frame
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)spriteList[i];
		s->collidedSprites.Clear();
		s->spriteCollisionData.Clear();
	}

	// O(n²) sprite-sprite collision pass with distance pre-check
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* s1 = (Sprite*)spriteList[i];
		if (!s1->CheckCollisionWithSprite()) continue;
		if (s1->ownerCollisionData.NumberOfElements() == 0) continue;

		for (int j = i + 1; j < spriteList.NumberOfElements(); j++)
		{
			Sprite* s2 = (Sprite*)spriteList[j];
			if (!s2->CheckCollisionWithSprite()) continue;
			if (s2->ownerCollisionData.NumberOfElements() == 0) continue;

			// Quick distance check before detailed collision testing
			float dx = s1->MapPositionX() - s2->MapPositionX();
			float dy = s1->MapPositionY() - s2->MapPositionY();
			float distSq = dx * dx + dy * dy;

			float maxDistance = (s1->Width() + s2->Width() + s1->Height() + s2->Height()) / 2.0f;
			if (distSq > maxDistance * maxDistance) continue;

			// Populate s1's spriteCollisionData with s2's shapes
			s1->spriteCollisionData.Clear();
			for (int k = 0; k < s2->ownerCollisionData.NumberOfElements(); k++)
			{
				s1->spriteCollisionData.InsertBack(s2->ownerCollisionData[k]);
			}

			// Detailed shape-based collision check
			bool hasCollision = false;
			for (int os = 0; os < s1->ownerCollisionData.NumberOfElements() && !hasCollision; os++)
			{
				CollisionData* shape1 = s1->ownerCollisionData[os];

				for (int os2 = 0; os2 < s2->ownerCollisionData.NumberOfElements(); os2++)
				{
					CollisionData* shape2 = s2->ownerCollisionData[os2];

					// Use shape-based collision detection with proper type dispatch
					bool collision = false;

					if (shape1->Type() == ColSegment)
					{
						CollisionSegment* seg1 = (CollisionSegment*)shape1;
						if (shape2->Type() == ColSegment)
						{
							CollisionSegment* seg2 = (CollisionSegment*)shape2;
							collision = seg1->DetectCollision(seg2,
								s1->MapPositionX(), s1->MapPositionY(),
								s2->MapPositionX(), s2->MapPositionY(),
								s1->TranslationX(), s1->TranslationY(),
								s1->Speed());
						}
						else if (shape2->Type() == ColCircle)
						{
							CollisionCircle* circ2 = (CollisionCircle*)shape2;
							collision = seg1->DetectCollision(circ2,
								s1->MapPositionX(), s1->MapPositionY(),
								s2->MapPositionX(), s2->MapPositionY(),
								s1->TranslationX(), s1->TranslationY(),
								s1->Speed());
						}
					}
					else if (shape1->Type() == ColCircle)
					{
						CollisionCircle* circ1 = (CollisionCircle*)shape1;
						if (shape2->Type() == ColSegment)
						{
							CollisionSegment* seg2 = (CollisionSegment*)shape2;
							collision = circ1->DetectCollision(seg2,
								s1->MapPositionX(), s1->MapPositionY(),
								s2->MapPositionX(), s2->MapPositionY(),
								s1->TranslationX(), s1->TranslationY(),
								s1->Speed());
						}
						else if (shape2->Type() == ColCircle)
						{
							CollisionCircle* circ2 = (CollisionCircle*)shape2;
							collision = circ1->DetectCollision(circ2,
								s1->MapPositionX(), s1->MapPositionY(),
								s2->MapPositionX(), s2->MapPositionY(),
								s1->TranslationX(), s1->TranslationY(),
								s1->Speed());
						}
					}

					if (collision)
					{
						hasCollision = true;
						break;
					}
				}
			}

			// Record collision results
			if (hasCollision)
			{
				s1->collidedSprites.InsertBack(s2->Name());
				s2->collidedSprites.InsertBack(s1->Name());
			}
		}
	}

	// sound effects
	// music
	// particleSystems
}

void GameNode::Id(int i)
{
	id = i;
}

int GameNode::Id()
{
	return id;
}

void GameNode::Name(const char* n)
{
	name = n;
}

const char* GameNode::Name()
{
	return name;
}

void GameNode::PaletteName(const char* n)
{
	paletteName = n;
}

GameNode* GameNode::Search(const char* n)
{
	return nullptr;
}

bool GameNode::Add(Sprite* s)
{
	if (spriteList.NumberOfElements() == spriteMaximum)	return false;

	// Assign sprite to the active map (mapList[0] for MVP)
	if (mapList.NumberOfElements() > 0)
	{
		Map* activeMap = (Map*)mapList[0];
		s->BelongToMapPtr(activeMap);
	}

	spriteList.InsertBack(s);
	return true;
}

bool GameNode::Add(Map* m)
{
	if (mapList.NumberOfElements() == mapMaximum)	return false;

	mapList.InsertBack(m);
	return true;
}

bool GameNode::AddSFX(const char*, const char*, bool, int)
{
	return false;
}

bool GameNode::AddMusic(const char*, const char*, bool)
{
	return false;
}

bool GameNode::AddMap(const char* name, const char* filename, Map::MapType mT)
{
	if (mapList.NumberOfElements() == mapMaximum) return false;

	// Allocate Map and Set Variables
	Map* m = (Map*)MEMPACK_AllocMem(&global.levelPack, sizeof(Map), "AddMapGameNode");
	::new (m) Map();
	m->Name(name);
	m->FileName(filename);
	m->SetMapType(mT);
	m->WorldPositionX(0);
	m->WorldPositionY(0);
	mapList.InsertBack(m);

	return true;
}

bool GameNode::Add(Map& m)
{
	if (mapList.NumberOfElements() + 1 > mapMaximum) return false;


	mapList.InsertBack(&m);
	return true;
}

bool GameNode::Add(Sprite& s)
{
	if (spriteList.NumberOfElements() + 1 > spriteMaximum) return false;
	

	spriteList.InsertBack(&s);
	return true;
}

void GameNode::AddLocalVariable(unsigned int i)
{
}

unsigned int GameNode::WorldWidth()
{
	return worldWidth;
}

unsigned int GameNode::WorldHeight()
{
	return worldHeight;
}

void GameNode::WorldWidth(unsigned int i)
{
	worldWidth = i;
}

void GameNode::WorldHeight(unsigned int i)
{
	worldHeight = i;
}

void GameNode::GetNewVariableStates()
{
}

void GameNode::DisplayTextNoMap()
{
}

void GameNode::UpdateScreen()
{
}

void GameNode::PlaySFX(const char* n)
{
}

void GameNode::PlayMusic(const char* n)
{
}

void GameNode::StopMusic(const char* n)
{
}

void GameNode::StopMidiFile(const char* n)
{
}

void GameNode::InitFPS()
{
}

void GameNode::EndTimer()
{
}

void GameNode::StartTimer()
{
}

void GameNode::FPStoMS(unsigned int)
{
}

void GameNode::Idle()
{
}

bool GameNode::ShowScrollingBoundingBox()
{
	return showScrollingBoundingBox;
}

void GameNode::ShowScrollingBoundingBox(bool b)
{
	showScrollingBoundingBox = b;
}

bool GameNode::QuitOnEscape()
{
	return quitOnEscape;
}

void GameNode::QuitOnEscape(bool b)
{
	quitOnEscape = b;
}

void GameNode::ViewPortPosition(unsigned int, unsigned int, bool)
{
}

void GameNode::DeleteCursor()
{
}

void GameNode::UpdateCursor()
{
}

void GameNode::Save(File&)
{
}

void GameNode::Load(File&)
{
}

DYNCREATEIMP(GameNode);