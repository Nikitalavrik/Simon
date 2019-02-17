#ifndef ALLOCATOR_H
# define ALLOCATOR_H

# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>

typedef struct	s_memlist
{
	void	*data;
	size_t	addr;
	size_t	size;
	struct	s_memlist *next;
	struct	s_memlist *prev;
}				t_memlist;

void			*mem_alloc(size_t size);
void			*mem_realloc(void *addr, size_t size);
void			mem_free(void *addr);
void			init_mem(size_t size);
t_memlist    	*create_node(size_t addr, size_t size);
t_memlist    	*add_node(size_t size);
t_memlist		*g_mem;

#endif