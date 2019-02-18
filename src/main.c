#include "../include/allocator.h"

void	see_mem(char *debug_tool)
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
	t_memlist	*begin;
	size_t		choice;
	char		*data;
	// char		*data;
	// char		*data2;
	// char		*data3;
	// char		*data4;

	// g_mem = NULL;

	// data = mem_alloc(30);
	// data = strcpy(data, "TEST1");
	// see_mem("1");
	// data2 = mem_alloc(40);
	// strcpy(data2, "TEST2");

	// data3 = mem_alloc(20);
	// strcpy(data3, "TEST3");

	// see_mem("1");
	// mem_free(data2);
	// see_mem("2");
	// data2 = mem_alloc(20);
	// strcpy(data2, "TEST2");
	// data4 = mem_alloc(20);
	// strcpy(data4, "TEST4");
	// see_mem("3");
	// mem_free(data2);
	// mem_free(data4);
	// see_mem("4");
	// data3 = mem_realloc(data3, 40);
	// see_mem("5");
	// while (1)
	// {
	// 	printf("\n1.Add memory block\n2.Delete memory block\n3.Realloc memory block\n");
	// 	printf("Your choice : ");
	// 	scanf("%d", &choice);
	// 	switch (choice)
	// 	{
	// 		case 1:
	// 			printf("Enter size : ");
	// 			scanf("%d", &choice);
	// 			printf("Enter what you wanna write : ");
	// 			scanf("%s", data);
	// 			strcpy(mem_alloc(choice), data);
	// 			see_mem("1");
	// 			break;
	// 		case 2:
	// 			printf("Enter addr : ");
	// 			scanf("%ld", &choice);
	// 			mem_free((void *)choice);
	// 			see_mem("2");
	// 		default:
	// 			exit(0);
	// 	}
	// }

	return (0);
}