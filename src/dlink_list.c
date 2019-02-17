#include "../include/allocator.h"

t_memlist    *create_node(size_t addr, size_t size)
{
    t_memlist *node;

    if (!(node = (t_memlist *)malloc(sizeof(t_memlist))) || !size)
        return (NULL);
    
    node->addr = addr;
    node->size = size;
    node->data = calloc(size, sizeof(void));
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

t_memlist    *add_node(size_t size)
{
    t_memlist *begin;

    begin = g_mem;
    while (begin->next)
        begin = begin->next;
    begin->next = create_node(begin->addr + begin->size, size);
    begin->next->prev = begin;
    return (begin->next);
}