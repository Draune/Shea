#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

int memcmp(const void*, const void*, size_t);
void* memcpy(void* dstptr, const void* srcptr, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);

#endif
