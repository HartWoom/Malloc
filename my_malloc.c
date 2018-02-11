/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Mains functions for malloc project
*/

#include "my_malloc.h"

list_t	allocated_list;
list_t	freed_list;
pthread_mutex_t	my_malloc_lock;

/* To malloc we first try to alloc a freed block, else we do a simple alloc */

void	*malloc(size_t size)
{
	static int	page_size = -1;
	void	*memory;

	if (page_size == -1)
		page_size = getpagesize();
	pthread_mutex_lock(&my_malloc_lock);
	if (!size) {
		pthread_mutex_unlock(&my_malloc_lock);
		return (NULL);
	}
	memory = alloc_freed_block(size);
	if (memory == NULL)
		memory = alloc_block(size, page_size);
	pthread_mutex_unlock(&my_malloc_lock);
	return (memory);
}

/* If the block freed is the last one allocated
   we give back memory to the system */

void	free(void *ptr)
{
	block_t	*elem = get_struct_ptr(ptr);

	if (elem == NULL)
		return ;
	pthread_mutex_lock(&my_malloc_lock);
	if (elem == allocated_list.last) {
		remove_block_to_list(&allocated_list, elem);
		sbrk(-elem->size);
	}
	else {
		remove_block_to_list(&allocated_list, elem);
		add_block_to_list(&freed_list, elem);
	}
	pthread_mutex_unlock(&my_malloc_lock);
}

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	block_t *elem = get_struct_ptr(ptr);

	if (ptr == NULL || size == 0) {
		return (malloc(size));
	}
	else if (elem != NULL && elem->size >= size)
		return ptr;
	else if (elem != NULL){
		new_ptr = malloc(size);
		memcpy(new_ptr, ptr, size);
	}
	return (new_ptr == NULL ? ptr : new_ptr);
}

void	*calloc(size_t nmemb, size_t size)
{
}
