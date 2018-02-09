/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Tools functions for malloc project
*/

#include "my_malloc.h"

t_block	*get_struct_ptr(void *mem_member)
{
	t_block	ref;
	void	*member_ref = &ref.memory;
	void	*block_ref = &ref;
	long int	diff = member_ref - block_ref;
	void	*result;

	if (mem_member == NULL)
		return (NULL);
	result = (void *) (mem_member) - diff;
	return (result);
}
