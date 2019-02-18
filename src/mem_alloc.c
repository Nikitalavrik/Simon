#include "../include/allocator.h"

void	*mem_alloc(size_t size)
{
    t_memlist   *ret;
    t_memlist   *new_node;

    ret = NULL;
    new_node = NULL;
    if (!size)
        return (NULL);

    if (!g_mem)
    {
        g_mem = create_node(size, 1);
        return (g_mem->addr);
    }
    if (ret = find_free(size))
    {
        ret->addr = calloc(size, sizeof(void));
        ret->is_free = 0;
        if (ABS(ret->size - size))
        {
            new_node = create_node(ABS(ret->size - size), 0);
            ret->next->prev = new_node;
            new_node->prev = ret;
            new_node->next = ret->next;
            ret->next = new_node;
        }
        ret->size = size;
        return (ret->addr);
    }
    return (add_node(size)->addr);
}