#include "../include/allocator.h"

t_memlist    *create_node(size_t size, size_t needfill)
{
    t_memlist *node;

    if (!(node = (t_memlist *)malloc(sizeof(t_memlist))) || !size)
        return (NULL);

    node->size = size;
    node->addr = needfill ? calloc(size, sizeof(void)) : NULL;
    node->is_free = !needfill;
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
    begin->next = create_node(size, 1);
    begin->next->prev = begin;
    return (begin->next);
}

t_memlist   *find_node(void *addr)
{
    t_memlist *begin;

    begin = g_mem;
    while (begin)
    {
        if (begin->addr == addr)
            return (begin);
        begin = begin->next;
    }
    return (NULL);
}

t_memlist   *find_free(size_t size)
{
    t_memlist *begin;

    begin = g_mem;
    while (begin)
    {
        if (begin->is_free && size <= begin->size)
            return (begin);
        begin = begin->next;
    }
    return (NULL);
}

void        free_node(t_memlist *node)
{
    if (node)
    {
        if (node->addr)
            free(node->addr);
        free(node);
    }
}

void        replace_node(t_memlist *old_node, t_memlist *new_node)
{
    new_node->next = old_node->next;
    new_node->prev = old_node->prev;
    if (old_node->prev)
        old_node->prev->next = new_node;
    if (old_node->next)
        old_node->next->prev = new_node;
    free_node(old_node);
}

void       del_node(t_memlist *node)
{
    t_memlist *begin;

    begin = node;
    if (begin->next)
        begin->next->prev = begin->prev;
    if (begin->prev)
        begin->prev->next = begin->next;
    if (!(begin->prev))
        g_mem = begin->next;
    free_node(begin);
}