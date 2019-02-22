#include "../include/allocator.h"

void	mem_dump()
{
	t_memlist	*begin;

	begin = g_mem;
	printf("--------------------\n");
	while (begin)
	{
		printf("addr: %15p data: %10s  size: %5li\n",
		begin->addr, (char *)begin->addr, begin->size);
		begin = begin->next;
	}
}

int     main()
{
	size_t		choice;
	char		*data;
	void		*addr;

	if (!testing(1000))
		printf("ERROR\n");
	// MENU
	// init_mem(VIRTUAL_SIZE);
	// while (1)
	// {
	// 	mem_dump();
	// 	printf("\n1.Add memory block\n2.Delete memory block\n3.Realloc memory block\n");
	// 	printf("Your choice : ");
	// 	scanf("%lu", &choice);
	// 	switch (choice)
	// 	{
	// 		case 1:
	// 			printf("Enter size : ");
	// 			scanf("%lu", &choice);
	// 			printf("Enter what you wanna write : ");
	// 			scanf("%s", data);
	// 			strcpy(mem_alloc(choice), data);
	// 			break ;
	// 		case 2:
	// 			printf("Enter addr : ");
	// 			scanf("%p", &addr);
	// 			mem_free(addr);
	// 			break ;
	// 		case 3:
	// 			printf("Enter addr : ");
	// 			scanf("%p", &addr);
	// 			printf("Enter new size : ");
	// 			scanf("%lu", &choice);
	// 			mem_realloc(addr, choice);
	// 			break ;
	// 		default:
	// 			exit(0);
	// 	}
	// }
	return (0);
}