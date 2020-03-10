#include <iostream>
#include <cstdio>
#include "allocator.h"

using namespace std;

char * p=NULL;
size_t totalSize;
size_t offset;

void makeAllocator(size_t Maxsize)
{
	if(!Maxsize)
		return;
	offset=0;
	totalSize=Maxsize;
	p=(char*)malloc(sizeof(char)*Maxsize);
	return;
}

char * alloc(size_t size)
{
	size_t newOffset = offset + size;
	if (p && (newOffset <= totalSize))
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
	p=NULL;
	return;
}