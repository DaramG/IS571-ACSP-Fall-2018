// vftable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>
#include <time.h>

#include <vector>

using namespace std;

#define KB_SIZE		1024
#define PAGE_SIZE	0x1000

typedef vector<HANDLE> HandleVector;
typedef vector<size_t> HandleSizeVector;

#define HEAP_STANDARD 0
#define HEAP_LAL 1
#define HEAP_LFH 2

// ////////////////////////////////////////////////////////////////////////////
// lec03_fixed_heap.exe / lec03_growable_heap / lec03_default_heap

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;

	HandleVector vec;
	HandleSizeVector siz;

	srand((unsigned)time(NULL));

	// Creating a size fixed heap
	size_t chunks = 100;
	size_t chunk_size = 0x100;

	HANDLE pChunk = NULL;
	HANDLE pOldChunk = NULL;

	//HANDLE pHeapBase = HeapCreate(0, 0, 0x1000000);
	//printf("A size-fixed heap was created : 0x%x\n", pHeapBase);

	HANDLE pHeapBase = GetProcessHeap();
	printf("Default heap : 0x%x\n", pHeapBase);
	
	//HANDLE pHeapBase = HeapCreate(0, 0, 0);
	//printf("A size-growable heap was created : 0x%x\n", pHeapBase);

	printf("Let's allocate %d chunks(size 0x%x) <press enter key>", chunks, chunk_size);
	getchar();

	size_t szRequest = 0;

	BOOL bResult;
	ULONG HeapInformation;
	BOOL bIsBreakable = false;

	size_t szBreak = 10;

	for (i = 0; i < chunks; i++) {
		pChunk = HeapAlloc(pHeapBase, 0, chunk_size);
		printf("A heap chunk was allocated : 0x%x\n", pChunk);
		
		vec.push_back(pChunk);
		
		if (i == 16 || i == 17) {
			printf("<press enter key>");
			getchar();
			bIsBreakable = false;
		}
	}

	printf("%d chunks are allocated <press enter key>", chunks);
	getchar();

	printf("%dth chunk(0x%x) was deallocated\n", 17, vec[17]);
	HeapFree(pHeapBase, 0, vec[17]);
	getchar();

	vec[17] = HeapAlloc(pHeapBase, 0, chunk_size);
	printf("A heap chunk was allocated : 0x%x\n", vec[17]);
	getchar();

	printf("%dth chunk(0x%x) was deallocated\n", 18, vec[18]);
	HeapFree(pHeapBase, 0, vec[18]);
	getchar();

	vec[18] = HeapAlloc(pHeapBase, 0, chunk_size);
	printf("A heap chunk was allocated : 0x%x\n", vec[18]);
	getchar();

	for (i = 0; i < 3; i++) {
		printf("%dth chunk(0x%x) was deallocated\n", i * 30 + 18, vec[i * 30 + 18]);
		HeapFree(pHeapBase, 0, vec[i * 30 + 18]);
	}
	getchar();

	for (i = 0; i < 15; i++) {
		pChunk = HeapAlloc(pHeapBase, 0, chunk_size);
		printf("A heap chunk was allocated : 0x%x\n", pChunk);
		vec.push_back(pChunk);
		getchar();
	}	
	getchar();
	
	return 0;
}

// ////////////////////////////////////////////////////////////////////////////
// lec03_crash.exe
/*
int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;

	HandleVector vec;
	HandleSizeVector siz;

	srand((unsigned)time(NULL));

	// Creating a size fixed heap
	size_t chunks = 100;
	size_t chunk_size = 0x100;

	HANDLE pChunk = NULL;

	HANDLE pHeapBase = HeapCreate(0, 0, 0x1000000);

	for (i = 0; i < chunks; i++) {
		pChunk = HeapAlloc(pHeapBase, 0, chunk_size);
		vec.push_back(pChunk);
	}

	HeapFree(pHeapBase, 0, vec[i / 4]);
	HeapFree(pHeapBase, 0, vec[i / 4]);

	return 0;
}
*/