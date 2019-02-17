#include "../include/allocator.h"

void	*mem_alloc(size_t size)
{
    if (!size)
            return (NULL);

    if (!g_mem)
    {
        g_mem = create_node(0, size);
        return (g_mem->data);
    }
    return (add_node(size)->data);
}