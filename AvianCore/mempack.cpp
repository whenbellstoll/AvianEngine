#include "globals.h"

void MEMPACK_Init(Mempack* mp, void* start, int size, const char* name)
{
    // size is the amount of bytes in the mempack

    mp->name = name;
    mp->packSize = size;

    mp->start = (char*)start;
    mp->firstFreeByte = (char*)start;

    mp->end = (char*)start + size;
    mp->lastFreeByte = (char*)start + size;

    mp->numBookmarks = 0;
    mp->sizeOfPrevAllocation = 0;

    // dont bother initializing the
    // bookmarks array, we'll overwrite it anyway

    printf("\n%s - MEMPACK_Init: start 0x%08x end 0x%08x\n", 
                name, (unsigned int)mp->start, (unsigned int)mp->end);
    
    printf("                    available memory %ld bytes\n\n", size);

    // size >> 10 = kilobytes
    // size >> 20 = megabytes
}

int MEMPACK_NumFreeBytes(Mempack* mp)
{
    return (char*)mp->lastFreeByte - (char*)mp->firstFreeByte;
}

void* MEMPACK_AllocMem(Mempack* mp, int size, const char* name)
{
    int numFreeBytes = MEMPACK_NumFreeBytes(mp);

    if (numFreeBytes < size)
    {
        printf("\nERROR: %s - MEMPACK_AllocMem unable to allocate %ld bytes for %s!\n", mp->name, size, name);
        printf("             %d bytes left, need %d more\n", numFreeBytes, size - numFreeBytes);

        // crash program
        while (true) {}
        // it's dirty, and I don't care.
    }

    // save where data has been allocated
    void* returnVal = mp->firstFreeByte;

    // increment the allocator for 
    // the next time it is used
    mp->firstFreeByte += size;

    // save the size, in case we want to realloc
    mp->sizeOfPrevAllocation = size;

    printf("%s - MEMPACK_AllocMem allocated %ld bytes: %s: %d bytes left\n",
        mp->name, size, name, MEMPACK_NumFreeBytes(mp));

    // size >> 10 = kilobytes
    // size >> 20 = megabytes

    return returnVal;
}

// This probably wont be used, but here it is if it's wanted,
void* MEMPACK_AllocHighMem(Mempack* mp, int size, const char* name)
{
    int numFreeBytes = MEMPACK_NumFreeBytes(mp);

    if (numFreeBytes < size)
    {
        printf("\nERROR: %s - MEMPACK_AllocHighMem unable to allocate %ld bytes for %s!\n", mp->name, size, name);
        printf("             %d bytes left, need %d more\n", numFreeBytes, size - numFreeBytes);

        // crash program
        while (true) {}
    }

    // decrement the allocator for 
    // current use
    mp->lastFreeByte -= size;

    // save where data has been allocated
    void* returnVal = mp->lastFreeByte;

    // Dont save the size, cause realloc
    // is only for low-side allocation

    printf("%s - MEMPACK_AllocHighMem allocated %ld bytes: %s: %d bytes left\n",
        mp->name, size, name, MEMPACK_NumFreeBytes(mp));

    // size >> 10 = kilobytes
    // size >> 20 = megabytes

    return returnVal;
}

void MEMPACK_EraseHighEnd(Mempack* mp)
{
    mp->lastFreeByte = mp->end;
    printf("%s - MEMPACK_EraseHighEnd: %d bytes left\n", mp->name, MEMPACK_NumFreeBytes(mp));
}

// This erases the previous allocation, and replaces it with another one
void* MEMPACK_ReallocMem(Mempack* mp, int size, const char* name)
{
    // decrement previous allocation
    mp->firstFreeByte -= mp->sizeOfPrevAllocation;

    int numFreeBytes = MEMPACK_NumFreeBytes(mp);

    if (numFreeBytes < size)
    {
        printf("\nERROR: %s - MEMPACK_ReallocMem unable to reallocate %ld bytes for %s!\n", mp->name, size, name);
        printf("             %d bytes left, need %d more\n", numFreeBytes, size - numFreeBytes);

        // crash program
        while (true) {}
    }

    // save where data has been allocated
    void* returnVal = mp->firstFreeByte;

    // increment the allocator for 
    // the next time it is used
    mp->firstFreeByte += size;

    // save the size, in case we want to realloc
    mp->sizeOfPrevAllocation = size;

    printf("%s - MEMPACK_ReallocMem reallocated %d bytes: %s: %d bytes left\n",
        mp->name, size, name, MEMPACK_NumFreeBytes(mp));

    // size >> 10 = kilobytes
    // size >> 20 = megabytes

    return returnVal;
}

// Add a bookmark
void MEMPACK_PushState(Mempack* mp)
{
    int bm = mp->numBookmarks;

    if (bm < 16)
    {
        mp->bookmarks[bm] = mp->firstFreeByte;

        mp->numBookmarks++;

        printf("%s - MEMPACK_PushState %d : 0x%08x : %d bytes left\n", 
                        mp->name, bm, (unsigned int)mp->firstFreeByte, MEMPACK_NumFreeBytes(mp));
    }

    else
    {
        printf("\nERROR: %s - MEMPACK_PushState out of bookmarks\n", mp->name);
    }

}

// erase all memory
void MEMPACK_Clean(Mempack* mp)
{
    mp->firstFreeByte = mp->start;
    mp->lastFreeByte = mp->end;
    mp->numBookmarks = 0;
    printf("%s - MEMPACK_Clean: %d bytes left\n", mp->name, MEMPACK_NumFreeBytes(mp));
}

void MEMPACK_PopState(Mempack* mp)
{
    if (mp->numBookmarks == 0)
    {
        printf("\nERROR: %s - MEMPACK_PopState has no bookmarks\n", mp->name);
    }

    else
    {
        // notice --bookmarks, that means
        // decrement, then use value

        mp->firstFreeByte = mp->bookmarks[--mp->numBookmarks];
    
        printf("%s - MEMPACK_PopState %d : 0x%08x : %d bytes left\n",
            mp->name, mp->numBookmarks, (unsigned int)mp->firstFreeByte, MEMPACK_NumFreeBytes(mp));
    }

    // size >> 10 = kilobytes
    // size >> 20 = megabytes
}

// only used it once
void MEMPACK_PopToState(Mempack* mp, int state)
{
    if (state < mp->numBookmarks)
    {
        mp->numBookmarks = state + 1;
        mp->firstFreeByte = mp->bookmarks[state];

        printf("%s - MEMPACK_PopToState %d : 0x%08x : %d bytes left\n",
            mp->name, mp->numBookmarks, (unsigned int)mp->firstFreeByte, MEMPACK_NumFreeBytes(mp));
    }

    else
    {
        printf("\nERROR: %s - MEMPACK_PopState attempted to grab\n", mp->name);
        printf("             bookmark[%d] when there is only %d total", state, mp->numBookmarks);
    }
}