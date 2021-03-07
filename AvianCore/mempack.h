#pragma once

struct Mempack
{
    const char* name;         // Which pack we are using
    int packSize;             // Ammount of bytes in pack
    char* start;              // first byte in allocator
    char* end;                // last byte in allocator
    char* firstFreeByte;	  // low-side allocation
    char* lastFreeByte;       // end-side allocation
    int sizeOfPrevAllocation; // self-explanatory
    int numBookmarks;		  // amount of bookmarks used
    char* bookmarks[16];	  // address of each bookmark
};


void MEMPACK_Init(Mempack* mp, void* start, int size, const char* name);

int MEMPACK_NumFreeBytes(Mempack* mp);

void* MEMPACK_AllocMem(Mempack* mp, int size, const char* name);

// This probably wont be used, but here it is if it's wanted,
void* MEMPACK_AllocHighMem(Mempack* mp, int size, const char* name);

void MEMPACK_EraseHighEnd(Mempack* mp);

// This erases the previous allocation, and replaces it with another one
void* MEMPACK_ReallocMem(Mempack* mp, int size, const char* name);

// Add a bookmark
void MEMPACK_PushState(Mempack* mp);

// erase all memory
void MEMPACK_Clean(Mempack* mp);

void MEMPACK_PopState(Mempack* mp);

// Crash Team Racing only used it once
void MEMPACK_PopToState(Mempack* mp, int state);