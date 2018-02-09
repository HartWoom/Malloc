/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Allocation's functions for malloc
*/

#include "my_malloc.h"

void	*alloc_freed_block(size_t size, int page_size)
{
	t_block	*elem = freed_list.first;

	if (elem == NULL)
		return (NULL);
	while (elem) {
		//TODO : Rajouter le split si block / page_size > size / page_size
		if ((size + sizeof(t_block)) <= elem->size) {
			remove_block_to_list(&freed_list, elem);
			add_block_to_list(&allocated_list, elem);
			return (elem->memory);
		}
		elem = elem->next;
	}
	return (NULL);
}

void	*alloc_block(size_t size, int page_size)
{
	t_block	*elem;
	int	nb_block = (size + sizeof(t_block)) / page_size;

	elem = sbrk((nb_block + 1) * page_size);
	if (elem == (void *) -1)
		return (NULL);
	elem->size = page_size * (nb_block + 1);
	add_block_to_list(&allocated_list, elem);
	return (elem->memory);
}
