#include "../include/allocator.h"

void			*mem_realloc(void *addr, size_t size)
{
    t_memlist *old_node;
    t_memlist *new_node;

    if(!(old_node = find_node(addr)) || !size)
        return (NULL);
    new_node = mem_alloc(size);
    new_node->addr = memmove(new_node->addr, old_node->addr,
                            old_node->size > size ? size : old_node->size);
    return (new_node->addr);
}