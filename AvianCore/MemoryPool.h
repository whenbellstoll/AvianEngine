#ifndef MEMORYPOOL
#define MEMORYPOOL

class MemoryPoolImp;

class FUNCORE_API MemoryPool
{
	MemoryPoolImp * imp;
	MemoryPool(const MemoryPool &);
	MemoryPool & operator = (const MemoryPool &);
public:
	MemoryPool(unsigned int s,unsigned int n = 128,bool OneTime = false);
	~MemoryPool();
	void * Alloc();
	void Free(void *);
};


#endif
