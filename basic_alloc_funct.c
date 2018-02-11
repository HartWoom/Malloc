/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Allocation's functions for malloc
*/

#include "my_malloc.h"

extern list_t	allocated_list;
extern list_t	freed_list;

void	*alloc_freed_block(size_t size)
{
	block_t	*elem = freed_list.first;

	if (elem == NULL)
		return (NULL);
	while (elem) {
		if (size <= elem->size) {
			remove_block_to_list(&freed_list, elem);
			add_block_to_list(&allocated_list, elem);
			return (void *) (elem + 1);
		}
		elem = elem->next;
	}
	return (NULL);
}

void	*alloc_block(size_t size, int page_size)
{
	block_t	*elem;
	int	nb_block = (size + sizeof(block_t)) / page_size;

	elem = sbrk((nb_block + 1) * page_size);
	if (elem == (void *) -1)
		return (NULL);
	elem->size = page_size * (nb_block + 1);
	add_block_to_list(&allocated_list, elem);
	return ((void *) (elem + 1));
}
