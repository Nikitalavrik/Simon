#include "../include/allocator.h"

void			*mem_realloc(void *addr, size_t size)
{
    t_memlist   *old_node;
    t_memlist   *new_node;
    t_memlist   *free_node;

    if (!addr)
        return (mem_alloc(size));
    if(!(old_node = find_node(addr)) || !size)
        return (NULL);
    free_node = find_free(size);
    if ((old_node->size < size) && free_node)
        free_node->size -= (size - old_node->size);
    else if (free_node)
        find_free(size)->size += old_node->size - size;
    new_node = create_node(size, 1);
    new_node->addr = memmove(new_node->addr, old_node->addr,
                            old_node->size > size ? size : old_node->size);
    replace_node(old_node, new_node);
    return (new_node->addr);
}