#include "../include/allocator.h"

void	mem_dump(char *debug_tool)
{
	t_memlist	*begin;

	begin = g_mem;
	printf("--------- %s --------\n", debug_tool);
	while (begin)
	{
		printf("size: %3li  addr: %p  %s  \n",
		begin->size, begin->addr, (char *)begin->addr);
		begin = begin->next;
	}
}

int     main()
{
	size_t		choice;
	char		*data;
	void		*addr;

	data = NULL;
	addr = NULL;
	choice = 0;
	while (1)
	{
		printf("\n1.Add memory block\n2.Delete memory block\n3.Realloc memory block\n");
		printf("Your choice : ");
		scanf("%lu", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter size : ");
				scanf("%lu", &choice);
				printf("Enter what you wanna write : ");
				scanf("%s", data);
				strcpy(mem_alloc(choice), data);
				mem_dump("add");
				break ;
			case 2:
				printf("Enter addr : ");
				scanf("%p", &addr);
				mem_free(addr);
				mem_dump("free");
				break ;
			case 3:
				printf("Enter addr : ");
				scanf("%p", &addr);
				printf("Enter new size : ");
				scanf("%lu", &choice);
				mem_realloc(addr, choice);
				mem_dump("realloc");
				break ;
			default:
				exit(0);
		}
	}
	return (0);
}