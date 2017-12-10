#ifndef _Tool
#define _Tool

#ifndef _stdlib
	#include <stdlib.h>
	#define _stdlib
#endif

#ifndef _stdio
	#include <stdio.h>
	#define _stdio
#endif

#define uchar unsigned char
#define uint unsigned int

void* Tool_warning(const char *c);

void* Tool_warningNull(const char *c);

void Tool_error(const char *c, int i);

void Tool_error1(const char *c);

void Tool_error1OutOfLength(const char *c);

void Tool_errorMemoryAllocation(const char *c, int i);

void Tool_error1MemoryAllocation(const char *c);

#endif
