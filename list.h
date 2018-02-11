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
	size_t	size;
	struct s_block *next;
	struct s_block *previous;
}	block_t;

typedef struct s_list
{
	struct s_block	*first;
	struct s_block	*last;
}	list_t;

void	add_block_to_list(list_t *list, block_t *block);
void	remove_block_to_list(list_t *list, block_t *block);

#endif
