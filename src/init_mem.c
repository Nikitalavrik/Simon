#include "../include/allocator.h"

void    init_mem(size_t size)
{
    g_mem = create_node(size, 0);
}