#include "../include/allocator.h"

int     testing(size_t count)
{
    t_memlist *iterator;
    void    *check;
    size_t  sum;
    size_t  size;
    size_t  c_mem_blocks;

    c_mem_blocks = 10;
    size = 100;
    while (c_mem_blocks--)
        mem_alloc(size);
    while(count--)
    {
        iterator = g_mem;
        c_mem_blocks = rand() % 10;
        while (c_mem_blocks--)
            iterator = iterator->next;
        check = iterator->addr;
        sum  = (size_t)check;
        mem_free(check);
        check = mem_alloc(size);
        if (sum != (size_t)check)
        {
            printf("sum   = %lu\n", sum);
            printf("check = %lu\n", (size_t)check);
            mem_dump();
            return (0);
        }
    }
    return (1);
}