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

void* Tool_error(const char *c, int i){
	printf("[<Error>: %s]\n",c);
	exit(i);
	return NULL;
}

void* Tool_error0(const char *c){
	return Tool_error(c,0);
}

void* Tool_errorMemoryAllocation(const char *c, int i){
	printf("[<Error>: <Memory Allocation Failed>: %s]\n",c);
	exit(i);
	return NULL;
}

void* Tool_error0MemoryAllocation(const char *c){
	return Tool_errorMemoryAllocation(c,0);
}

void* Tool_errorMemoryDeallocation(const char *c, int i){
	printf("[<Error>: <Memory Deallocation Failed>: %s]\n",c);
	exit(i);
	return NULL;
}

void* Tool_error0MemoryDeallocation(const char *c){
	return Tool_errorMemoryDeallocation(c,0);
}