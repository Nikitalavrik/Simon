#include "../include/allocator.h"

void    init_mem(size_t size)
{
    g_mem = (void *)malloc(sizeof(void) * size);
}