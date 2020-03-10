#include <iostream>
#include "allocator.h"

using namespace std;

char * p;
uint32_t totalSize;
uint32_t offset;

void makeAllocator(uint32_t Maxsize)
{
	if(!Maxsize)
		return;
	offset=0;
	totalSize=Maxsize;
	p=(char*)malloc(sizeof(char)*Maxsize);
	return;
}

char * alloc(uint32_t size)
{
	uint32_t newOffset = offset + size;
	if (newOffset <= totalSize)
	{
		char* ptr = p + offset;
		offset = newOffset;
		return ptr;
	}
	return NULL;
}

void reset()
{
	offset=0;
	totalSize=0;
	free(p);
	return;
}