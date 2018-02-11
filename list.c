/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Basics functions for linked list
*/

#include "list.h"

void	add_block_to_list(list_t *list, block_t *block)
{
	block->previous = list->last;
	block->next = NULL;
	if (list->first == NULL && list->last == NULL) {
		list->first = block;
		list->last = block;
	} else {
		list->last->next = block;
		list->last = block;
	}
}

void	remove_block_to_list(list_t *list, block_t *block)
{
	if (block == list->last && block == list->first) {
		list->first = NULL;
		list->last = NULL;
	} else if (block == list->last) {
		list->last = block->previous;
		list->last->next = NULL;
	} else if (block == list->first) {
		list->first = block->next;
		list->first->previous = NULL;
	} else {
		block->previous->next = block->next;
		block->next->previous = block->previous;
	}
}
