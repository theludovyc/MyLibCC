#ifndef _stdlib
	#include <stdlib.h>
	#define _stdlib
#endif

#ifndef _stdio
	#include <stdio.h>
	#define _stdio
#endif

#define _Tool

void* Tool_warning(const char *c){
	printf("[<Warning>: %s]\n",c);
	return NULL;
}

void* Tool_warningNull(const char *c){
	printf("[<Warning>: %s is NULL!]\n",c);
	return NULL;
}

void Tool_error(const char *c, int i){
	printf("[<Error>: %s]\n",c);
	exit(i);
}

void Tool_error0(const char *c){
	Tool_error(c,0);
}

void Tool_error0OutOfLength(const char *c){
	printf("[<Error>: %s: Out of Length!]\n", c);
	exit(0);
}

void Tool_errorMemoryAllocation(const char *c, int i){
	printf("[<Error>: <Memory Allocation Failed>: %s]\n",c);
	exit(i);
}

void Tool_error0MemoryAllocation(const char *c){
	Tool_errorMemoryAllocation(c,0);
}

void Tool_errorMemoryDeallocation(const char *c, int i){
	printf("[<Error>: <Memory Deallocation Failed>: %s]\n",c);
	exit(i);
}

void Tool_error0MemoryDeallocation(const char *c){
	Tool_errorMemoryDeallocation(c,0);
}