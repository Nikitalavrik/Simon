#ifndef ALLOCATOR_H
# define ALLOCATOR_H

# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>

# define ABS(x) ((x < 0) ? -x : x)

typedef struct	s_memlist
{
	size_t	number;
	void	*addr;
	size_t	is_free;
	size_t	size;
	struct	s_memlist *next;
	struct	s_memlist *prev;
}				t_memlist;

void			mem_dump(char *debug_tool);
void			*mem_alloc(size_t size);
void			*mem_realloc(void *addr, size_t size);
void			mem_free(void *addr);
void			del_node(t_memlist *node);
void        	replace_node(t_memlist *old_node, t_memlist *new_node);

t_memlist   	*find_node(void *addr);
t_memlist    	*create_node(size_t size, size_t needfill);
t_memlist    	*add_node(size_t size);
t_memlist		*find_free(size_t size);
t_memlist		*g_mem;

#endif