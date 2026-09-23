#include "../globals.h"


void WrappingAlgorithm::Compute()
{
}

void WrappingAlgorithm::Adjust()
{
}

Rect* WrappingAlgorithm::Sources()
{
	return nullptr;
}

Rect* WrappingAlgorithm::Destinations()
{
	return nullptr;
}

WrappingAlgorithm::WrappingAlgorithm()
{
}

WrappingAlgorithm::WrappingAlgorithm(const Rect& rc1, const Rect& rc2, bool InViewPort, int x, int y)
{
}

void WrappingAlgorithm::Position(int, int)
{
}

void WrappingAlgorithm::Load(File&)
{
}

void WrappingAlgorithm::Save(File&)
{
}

void Map::InitMasterMap(const char*, const char*, int)
{
}

void Map::InitStandardMap(const char*, const char*, int, int, int, bool, Rect)
{
}

void Map::InitWrappedMap(const char*, const char*, int, int, int, bool, Rect)
{
}

void Map::Id(int)
{
}

void Map::Init()
{
}

void Map::LoadMap()
{
    // open file
    FILE* f = fopen(fileName, "rb");

    if (!f)
    {
        printf("\nFailed to open %s\n", fileName);
        glfwTerminate();
        while (true) {}
    }

    // get size
    fseek(f, 0L, SEEK_END);
    int sz = ftell(f);
    fseek(f, 0L, SEEK_SET);

    // allocate memory
    char* hex = (char*)MEMPACK_AllocMem(&global.levelPack, sz, "map file");

    // read
    fread(hex, 1, sz, f);

    // close
    fclose(f);

    // parse
    unsigned short texW, texH, dataOffset;
    memcpy(&dataOffset, &hex[10], sizeof(short));
    memcpy(&texW, &hex[18], sizeof(short));
    memcpy(&texH, &hex[22], sizeof(short));

    // Send from CPU to GPU
    // Create Texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    const int texPixelsSize = sz - dataOffset;

    // allocate data
    void* pboMem = MEMPACK_AllocMem(&global.mappboPack, texPixelsSize, "texture pixels");

    // Set the data, with offset, size, and ram pointer
    glBufferSubData(GL_PIXEL_UNPACK_BUFFER, (int)pboMem, texPixelsSize, &hex[dataOffset]);

    // Now set glTexImage2D witih pboOffset instead of a RAM address, OpenGL uses the last parameter 
    // as a buffer offset when it sees GL_PIXEL_UNPACK_BUFFER is binded and active
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, texW, texH, 0, GL_BGR, GL_UNSIGNED_BYTE, (void*)pboMem);

    // erase CPU allocation
    MEMPACK_ReallocMem(&global.levelPack, 0, "erasing texture file");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float vertices[] = {
        // positions                // texture coords
         0.0f, (float)texH,         0.0f, 1.0f, // top left 
         0.0f, 0.0f,                0.0f, 0.0f, // bottom left
         (float)texW, (float)texH,  1.0f, 1.0f, // top right
         (float)texW, 0.0f,         1.0f, 0.0f  // bottom right
    };

    // each vertex is 4 bytes large, so to get the starting vertex
    // of any given sprite, divide the amount of memory allocated by sizeof(Vertex).
    // this will be used in the render loop
    startingVertex = (int)global.mapvboPack.firstFreeByte / (sizeof(float) * 4);

    // allocate data
    void* vboMem = MEMPACK_AllocMem(&global.mapvboPack, sizeof(vertices), "four vertices");

    // copy data
    glBufferSubData(GL_ARRAY_BUFFER, (int)vboMem, sizeof(vertices), vertices);
    rect.top = 0;
    rect.left = 0;
    rect.right = texW;
    rect.bottom = texH;
    width = texW;
    height = texH;
    printf("\n Loaded map complete. %s \n ", fileName);
}

void Map::FreeMap()
{
    // nothing for now
}

void Map::DisplayMasterMap()
{
}

void Map::DisplayStandardMap()
{
}

void Map::DisplayWrappedMap()
{
}

void Map::DummyDisplay()
{
}

void Map::UpdateStandardMap()
{
}

void Map::UpdateWrappedMap()
{
}

void Map::DisplayMap()
{
    
    // layer (what draws on top of what)
    glUniform1f(0, 0.99999f);//(zOrder / 100.0f) + 1); // always + 1 so that sprites always draw on top of maps.

    // position (convert the map's world position, in pixels, to normalized device coordinates.
    // -1 is the screen origin (bottom-left); adding the scaled world offset lets the map scroll.)
    glUniform1f(1, -1 + worldPositionX * (2.0f / global.width));
    glUniform1f(2, -1 + worldPositionY * (2.0f / global.height));

    // scale
    glUniform1f(3, 2 / (float)global.width );
    glUniform1f(4, 2 / (float)global.height );

    // transparent color
    GLint pos = glGetUniformLocation(global.program, "transparentB");
    if (pos != -1)
    {
        glUniform1f(pos, transparencyColor.b / 255.0f);
        glUniform1f(pos + 1, transparencyColor.g / 255.0f);
        glUniform1f(pos + 2, transparencyColor.r / 255.0f);

    }
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLE_STRIP, startingVertex, 4);
}

void Map::ShowMapCollision(COLORREF)
{
}

void Map::ClearVariableMapList()
{
}

void Map::InitCollision()
{
}

Map::Map()
{
}

Map::Map(const Map&)
{
}

Map::Map(const char* na, const char* file, MapType mt, int x, int y, int spacePartion, bool isMaster)
{
    name = na;
    fileName = file;
    mType = mt;
    worldPositionX = x;
    worldPositionY = y;
    isMasterMap = isMaster;
    spacePartitionGridSize = spacePartion;
    transparencyColor = RGB(128, 255, 255); // cyan
    speedX = 0;
    speedY = 0;
    zOrder = 1;
    LoadMap(); // loads the bitmap declared in fileName
    InitGrid(); // initialize spatial partition grid for collision optimization
}

Map::~Map()
{
}

Map* Map::Search(const char*)
{
	return nullptr;
}

void Map::Name(const char* n)
{
    name = n;
}

const char* Map::Name()
{
	return name;
}

void Map::FileName(const char* fn)
{
    fileName = fn;
    LoadMap();
}

const char* Map::FileName()
{
    return fileName;
}

void Map::SetMapType(MapType mt)
{
    mType = mt;
}

unsigned int Map::Height()
{
	return height;
}

unsigned int Map::Width()
{
	return width;
}

float Map::WorldPositionX()
{
	return worldPositionX;
}

float Map::WorldPositionY()
{
	return worldPositionY;
}

bool Map::IsMasterMap()
{
	return isMasterMap;
}

void Map::TransparencyColor(COLORREF)
{
}

COLORREF Map::TransparencyColor()
{
	return COLORREF();
}

bool Map::UseTransparency()
{
	return false;
}

void Map::UseTransparency(bool)
{
}

void Map::SpeedX(float f)
{
    speedX = f;
}

void Map::SpeedY(float f)
{
    speedY = f;
}

float Map::SpeedX()
{
	return speedX;
}

float Map::SpeedY()
{
	return speedY;
}

int Map::Id()
{
	return id;
}

int Map::ViewPortX()
{
	return 0;
}

int Map::ViewPortY()
{
	return 0;
}

void Map::Visible(bool b)
{
    visible = b;
}

bool Map::Visible()
{
	return visible;
}

void Map::ScrollRatioX(float f)
{
	scrollingRatioX = f;
}

void Map::ScrollRatioY(float f)
{
	scrollingRatioY = f;
}

float Map::ScrollRatioX()
{
	return scrollingRatioX;
}

float Map::ScrollRatioY()
{
	return scrollingRatioY;
}

int Map::ZOrder()
{
	return zOrder;
}

void Map::WorldPositionXInc(float inc, float max)
{
	worldPositionX += inc;
	if (worldPositionX > max) worldPositionX = max;
}

void Map::WorldPositionXDec(float dec, float min)
{
	worldPositionX -= dec;
	if (worldPositionX < min) worldPositionX = min;
}

void Map::WorldPositionYInc(float inc, float max)
{
	worldPositionY += inc;
	if (worldPositionY > max) worldPositionY = max;
}

void Map::WorldPositionYDec(float dec, float min)
{
	worldPositionY -= dec;
	if (worldPositionY < min) worldPositionY = min;
}

void Map::WorldPositionX(float x)
{
	worldPositionX = x;
}

void Map::WorldPositionY(float y)
{
	worldPositionY = y;
}

void Map::ShowMapCollision(bool)
{
}

//bool Map::Add(Alarm)
//{
//	return false;
//}

bool Map::Add(Alarm*)
{
	return false;
}

void Map::AlarmMaximum(int)
{
}

int Map::AlarmMaximum(void)
{
	return 0;
}

int Map::AlarmCount(void)
{
	return 0;
}

void Map::AddCollisionData(CollisionSegment cs)
{
	// Create a new CollisionSegment on the heap and store pointer
	CollisionSegment* pSegment = new CollisionSegment(cs);
	collisionData.InsertBack((CollisionData*)pSegment);
}

void Map::AddCollisionData(CollisionCircle cc)
{
	// Create a new CollisionCircle on the heap and store pointer
	CollisionCircle* pCircle = new CollisionCircle(cc);
	collisionData.InsertBack((CollisionData*)pCircle);
}

void Map::RemoveCollisionData(unsigned int, unsigned int)
{
}

void Map::InitGrid()
{
	// Initialize partition grid with conservative cell size for MVP
	// Cell size = 2x typical sprite size for safety; adjust gridRows/gridColumns accordingly
	if (spacePartitionGridSize <= 0)
	{
		spacePartitionGridSize = 64;  // default cell size in pixels
	}

	gridRows = (height + spacePartitionGridSize - 1) / spacePartitionGridSize;
	gridColumns = (width + spacePartitionGridSize - 1) / spacePartitionGridSize;

	// Resize 2D grid to hold sprite lists
	gridLists.Resize(gridColumns);
	for (int i = 0; i < gridColumns; i++)
	{
		gridLists[i].Resize(gridRows);
	}
}

void Map::SpacePartitionGridSize(unsigned int size)
{
	spacePartitionGridSize = size;
}

int Map::SpacePartitionGridSize()
{
	return spacePartitionGridSize;
}

void Map::AddLocalVariable(unsigned int)
{
}

void Map::GridCoordsFromWorld(float worldX, float worldY, int& gridX, int& gridY)
{
	// Convert world coordinates to grid cell indices
	// Clamp to valid grid range
	gridX = (int)(worldX / spacePartitionGridSize);
	gridY = (int)(worldY / spacePartitionGridSize);

	if (gridX < 0) gridX = 0;
	if (gridY < 0) gridY = 0;
	if (gridX >= gridColumns) gridX = gridColumns - 1;
	if (gridY >= gridRows) gridY = gridRows - 1;
}

void Map::GetGridCellsForBounds(float left, float top, float right, float bottom,
								 int& minX, int& maxX, int& minY, int& maxY)
{
	// Get the range of grid cells occupied by a bounding box
	GridCoordsFromWorld(left, top, minX, minY);
	GridCoordsFromWorld(right, bottom, maxX, maxY);

	// Ensure valid range
	if (minX > maxX) { int t = minX; minX = maxX; maxX = t; }
	if (minY > maxY) { int t = minY; minY = maxY; maxY = t; }
}

void Map::GetGridCellForPosition(float worldX, float worldY, int& outGridX, int& outGridY)
{
	// Convert world position to grid cell coordinates
	outGridX = (int)(worldX / spacePartitionGridSize);
	outGridY = (int)(worldY / spacePartitionGridSize);

	// Clamp to grid bounds
	if (outGridX < 0) outGridX = 0;
	if (outGridX >= gridColumns) outGridX = gridColumns - 1;
	if (outGridY < 0) outGridY = 0;
	if (outGridY >= gridRows) outGridY = gridRows - 1;
}

void Map::GetGridCellsForBounds(float x, float y, float width, float height, Array<int>& outGridXs, Array<int>& outGridYs)
{
	outGridXs.Clear();
	outGridYs.Clear();

	// Get min/max grid cells for the bounding box
	int minGridX, minGridY, maxGridX, maxGridY;

	GetGridCellForPosition(x, y, minGridX, minGridY);
	GetGridCellForPosition(x + width, y + height, maxGridX, maxGridY);

	// Collect all grid cell indices that overlap the bounds
	for (int gx = minGridX; gx <= maxGridX; gx++)
	{
		for (int gy = minGridY; gy <= maxGridY; gy++)
		{
			outGridXs.InsertBack(gx);
			outGridYs.InsertBack(gy);
		}
	}
}

void Map::GetCollisionDataInBounds(float x, float y, float width, float height, Array<CollisionData*>& outCollisionData)
{
	outCollisionData.Clear();

	// For MVP, return all map collision data
	// The partition grid infrastructure is in place for future optimization
	// but for now we simply return all shapes the map has
	for (int i = 0; i < collisionData.NumberOfElements(); i++)
	{
		outCollisionData.InsertBack(collisionData[i]);
	}
}

void Map::Unused(bool)
{
}

bool Map::Unused()
{
	return false;
}

void Map::Pause(bool)
{
}

bool Map::Pause()
{
	return false;
}

void Map::Use(const char*)
{
}

Map* Map::CreateMap()
{
	return nullptr;
}

node* Map::Clone()
{
	return nullptr;
}

void Map::Load(File&)
{
}

void Map::Save(File&)
{
}

DYNCREATEIMP(Map);

MapPTR::MapPTR()
{
}

MapPTR::MapPTR(Map*)
{
}

MapPTR::MapPTR(const char*)
{
}

Map* MapPTR::operator->()
{
	return nullptr;
}

Map& MapPTR::operator*()
{
	// TODO: insert return statement here
    Map* r = nullptr;
    return *r;
}

MapPTR& MapPTR::operator=(Map*)
{
	// TODO: insert return statement here
    MapPTR* r = nullptr;
    return *r;
}

MapPTR::operator Map* ()
{
    return mapPtr;
}
