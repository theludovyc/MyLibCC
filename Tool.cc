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

void* Tool_nullWarning(const char *c){
	printf("[<Warning>: %s is NULL!]\n",c);
	return NULL;
}

void *error(const char *c, int i){
	printf("[<Error>: %s]\n",c);
	exit(i);
	return NULL;
}

void *Tool_error0(const char *c){
	return error(c,0);
}

void *errorMemoryAllocation(const char *c, int i){
	printf("[<Memory Allocation Failed>: %s]\n",c);
	exit(i);
	return NULL;
}

void *Tool_errorMemoryAllocation0(const char *c){
	return errorMemoryAllocation(c,0);
}

void *errorMemoryDeallocation(const char *c, int i){
	printf("[<Memory Deallocation Failed>: %s]\n",c);
	exit(i);
	return NULL;
}

void *errorMemoryDeallocation0(const char *c){
	return errorMemoryDeallocation(c,0);
}