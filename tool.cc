#ifndef _stdlib
	#include <stdlib.h>
	#define _stdlib
#endif

#ifndef _stdio
	#include <stdio.h>
	#define _stdio
#endif

#define _Tool

#define uchar unsigned char
#define uint unsigned int

void* Tool_warning(const char *c){
	printf("[<Warning>: %s]\n", c);
	return NULL;
}

void* Tool_warningNull(const char *c){
	printf("[<Warning>: %s is NULL!]\n", c);
	return NULL;
}

void Tool_error(const char *c, int i){
	printf("[<Error>: %s]\n", c);
	exit(i);
}

void Tool_error1(const char *c){
	Tool_error(c, 1);
}

void Tool_error1OutOfLength(const char *c){
	printf("[<Error>: %s: Out of Length!]\n", c);
	exit(1);
}

void Tool_errorMemoryAllocation(const char *c, int i){
	printf("[<Error>: <Memory Allocation Failed>: %s]\n", c);
	exit(i);
}

void Tool_error1MemoryAllocation(const char *c){
	Tool_errorMemoryAllocation(c, 1);
}

void Tool_errorMemoryReallocation(const char *c, int i){
	printf("[<Error>: <Memory Reallocation Failed> : %s]\n", c);
	exit(i);
}

void Tool_error1MemoryReallocation(const char *c){
	Tool_errorMemoryReallocation(c, 1);
}

void Tool_errorMemoryFree(const char *c, int i){
	printf("[<Error>: <Memory Free Failed>: %s]\n", c);
	exit(i);
}

void Tool_error1MemoryFree(const char *c){
	Tool_errorMemoryFree(c, 1);
}
