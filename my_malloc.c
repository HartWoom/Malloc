/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Main functions for malloc project
*/

#include "my_malloc.h"

void	*malloc(size_t size)
{
	static int	page_size = -1;
	void	*memory;

	if (page_size == -1)
		page_size = getpagesize();
	if (!size)
		return NULL;
	memory = alloc_freed_block(size, page_size);
	//on tente d'abord d'allouer un membre de la liste freed
	//sinon on fait une allocation classique
	if (!memory)
		memory = alloc_block(size, page_size);
	return (memory);
}

void	free(void *ptr)
{
	//trouver le block à partir du membre
	//si le block est à la fin de la liste allocated => sbrk négatif
	//sinon déplacer le block de liste allocated à freed en faisant le remove en 1er
	
}

void	*realloc(void *ptr, size_t size)
{
	//trouver le block associer au ptr
	/* si size == 0 ou ptr == NULL => malloc(block->size)
	 + memcpy de ptr dans new_ptr */ 
	//sinon malloc(block->size + size) + memcpy ptr dans new_ptr
	//return new_ptr;
}
