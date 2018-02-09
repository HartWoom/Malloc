/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Mains functions for malloc project
*/

#include "my_malloc.h"

/* To malloc we first try to alloc a freed block, else we do a simple alloc */

void	*malloc(size_t size)
{
	static int	page_size = -1;
	void	*memory;

	if (page_size == -1)
		page_size = getpagesize();
	if (!size)
		return (NULL);
	memory = alloc_freed_block(size, page_size);
	if (memory == NULL)
		memory = alloc_block(size, page_size);
	return (memory);
}

void	free(void *ptr)
{
	t_block	*elem = get_struct_ptr(ptr);

	if (elem == allocated_list.last) {
		remove_block_to_list(&allocated_list, elem);
		sbrk(-1 * (elem->size));
	}
	else {
		remove_block_to_list(&allocated_list, elem);
		add_block_to_list(&freed_list, elem);
	}
	//si le block est à la fin de la liste allocated => sbrk négatif
	//sinon déplacer le block de liste allocated à freed en faisant le remove en 1er
}

void	*realloc(void *ptr, size_t size)
{
	t_block *elem = get_struct_ptr(ptr);
	void	*new_ptr;

	if (ptr == NULL && size != 0) {
		return (malloc(size));
	}
	else if (ptr != NULL && size == 0) {
		free(ptr);
		return (NULL);
	}
	/* si size == 0 ou ptr == NULL => malloc(block->size)
	 + memcpy de ptr dans new_ptr */ 
	//sinon malloc(block->size + size) + memcpy ptr dans new_ptr
	//return new_ptr;
}
