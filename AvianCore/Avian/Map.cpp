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
    char* hex = (char*)MEMPACK_AllocMem(&global.ramPack, sz, "map file");

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
    void* pboMem = MEMPACK_AllocMem(&global.pboPack, texPixelsSize, "texture pixels");

    // Set the data, with offset, size, and ram pointer
    glBufferSubData(GL_PIXEL_UNPACK_BUFFER, (int)pboMem, texPixelsSize, &hex[dataOffset]);

    // Now set glTexImage2D witih pboOffset instead of a RAM address, OpenGL uses the last parameter 
    // as a buffer offset when it sees GL_PIXEL_UNPACK_BUFFER is binded and active
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, texW, texH, 0, GL_BGR, GL_UNSIGNED_BYTE, (void*)pboMem);

    // erase CPU allocation
    MEMPACK_ReallocMem(&global.ramPack, 0, "erasing texture file");

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
    startingVertex = (int)global.vboPack.firstFreeByte / (sizeof(float) * 4);

    // allocate data
    void* vboMem = MEMPACK_AllocMem(&global.vboPack, sizeof(vertices), "four vertices");

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

    // position
    glUniform1f(1, -1);//worldPositionX);
    glUniform1f(2, -1);//worldPositionY);

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
}

Map::~Map()
{
}

Map* Map::Search(const char*)
{
	return nullptr;
}

void Map::Name(const char*)
{
}

const char* Map::Name()
{
	return nullptr;
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

unsigned int Map::Height()
{
	return 0;
}

unsigned int Map::Width()
{
	return 0;
}

float Map::WorldPositionX()
{
	return 0.0f;
}

float Map::WorldPositionY()
{
	return 0.0f;
}

bool Map::IsMasterMap()
{
	return false;
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

void Map::ScrollRatioX(float)
{
}

void Map::ScrollRatioY(float)
{
}

float Map::ScrollRatioX()
{
	return 0.0f;
}

float Map::ScrollRatioY()
{
	return 0.0f;
}

int Map::ZOrder()
{
	return zOrder;
}

void Map::WorldPositionXInc(float, float)
{
}

void Map::WorldPositionXDec(float, float)
{
}

void Map::WorldPositionYInc(float, float)
{
}

void Map::WorldPositionYDec(float, float)
{
}

void Map::WorldPositionX(float)
{
}

void Map::WorldPositionY(float)
{
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

void Map::AddCollisionData(CollisionSegment)
{
}

void Map::AddCollisionData(CollisionCircle)
{
}

void Map::RemoveCollisionData(unsigned int, unsigned int)
{
}

void Map::InitGrid()
{
}

void Map::SpacePartitionGridSize(unsigned int)
{
}

int Map::SpacePartitionGridSize()
{
	return 0;
}

void Map::AddLocalVariable(unsigned int)
{
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
}

MapPTR& MapPTR::operator=(Map*)
{
	// TODO: insert return statement here
}

MapPTR::operator Map* ()
{
}
