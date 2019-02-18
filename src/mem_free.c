#include "../include/allocator.h"

void			mem_free(void *addr)
{
    t_memlist *node;

    node = NULL;
    if (!(node = find_node(addr)))
        return ;
    node->is_free = 1;
    free(node->addr);
    node->addr = NULL;
    if (node->prev && node->prev->is_free)
        node->prev->size += node->size;
    else if (node->next && node->next->is_free)
        node->next->size += node->size;
    else
        return ;
    del_node(node);
}