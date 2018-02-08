/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Header file for linked list
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

typedef struct s_block
{
	void	*memory;
	struct s_block *next;
	struct s_block *previous;
	size_t	size;
}	t_block;

typedef struct s_list
{
	struct s_block *first;
	struct s_block *last;
}	t_list;

void	add_block_to_list(t_list *list, t_block *block);
void	remove_block_to_list(t_list *list, t_block *block);

#endif
