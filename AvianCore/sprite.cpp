#include "globals.h"

SpriteStruct* Sprite_Init(const char* filename)
{
    printf("Loading sprite: %s\n", filename);

    SpriteStruct* sprite = (SpriteStruct*)MEMPACK_AllocMem(&global.ramPack, sizeof(SpriteStruct), "sprite");

    // open file
    FILE* f = fopen(filename, "rb");

    if (!f)
    {
        printf("\nFailed to open %s\n", filename);
        glfwTerminate();
        while (true) {}
    }

    // get size
    fseek(f, 0L, SEEK_END);
    int sz = ftell(f);
    fseek(f, 0L, SEEK_SET);

    // allocate memory
    char* hex = (char*)MEMPACK_AllocMem(&global.ramPack, sz, "texture file");

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

    // Never do this
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, texW, texH, 0, GL_BGR, GL_UNSIGNED_BYTE, &hex[dataOffset]);
    // because we have no control over where in the GPU memory the texture copies to.
    // Instead, do the following

    // Create Texture
    glGenTextures(1, &sprite->texture);
    glBindTexture(GL_TEXTURE_2D, sprite->texture);

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
    sprite->startingVertex = (int)global.vboPack.firstFreeByte / (sizeof(float) * 4);

    // allocate data
    void* vboMem = MEMPACK_AllocMem(&global.vboPack, sizeof(vertices), "four vertices");

    // copy data
    glBufferSubData(GL_ARRAY_BUFFER, (int)vboMem, sizeof(vertices), vertices);

    return sprite;
}