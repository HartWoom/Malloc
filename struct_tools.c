/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Tools functions for malloc project
*/

#include "my_malloc.h"

extern list_t	allocated_list;

block_t	*get_struct_ptr(void *mem_member)
{
	block_t	*ref = allocated_list.first;

	if (mem_member == NULL)
		return (NULL);
	while (ref) {
		if ((void *) (ref + 1) == mem_member)
			return (ref);
		ref = ref->next;
	}
	return (NULL);
}
