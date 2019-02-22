#include "../include/allocator.h"

int     testing(size_t count)
{
    void    *check;
    size_t  sum;

    init_mem(1024);
    check = mem_alloc(10);
    sum  = (size_t)check;
    while(count--){
        mem_free(check);
        check = mem_alloc(10);
        if (sum != (size_t)check)
        {
            printf("sum   = %lu\n", sum);
            printf("check = %lu\n", (size_t)check);
            mem_dump();
            return (0);
        }

    }
    // check = calloc(10, sizeof(void));
    // sum = (size_t)check;
    // free(check);
    // check = calloc(10, sizeof(void));
    // printf("sum = %lu\ncheck = %lu\n", sum, (size_t)check);
    return (1);
}