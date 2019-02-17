#include "../include/allocator.h"

int     main()
{
	t_memlist	*test;
	char		*data;
	char		*data2;
	char		*data3;

	test = create_node(0, 10);
	test->data = strcat(test->data, "TEST");
	printf("%s\n", (char *)test->data);

	g_mem = NULL;
	data = mem_alloc(10);
	data = strcpy(data, "TEST1");
	data2 = mem_alloc(10);
	data2 = strcpy(data2, "TEST2");
	data3 = mem_alloc(10);
	data3 = strcpy(data3, "TEST3");

	while (g_mem)
	{
		printf("%s\n", g_mem->data);
		g_mem = g_mem->next;
	}
	return (0);
}