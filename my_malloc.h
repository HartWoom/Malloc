/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Header file for memory function
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

/* Globals lists for Malloc */

t_list		allocated_list;
t_list		freed_list;

/* Memory allocation */

void	*malloc(size_t size);

/* Free memory */

void	free(void *ptr);

/* Re alloc memory */

void	*realloc(void *ptr, size_t size);

/* Basic allocation function */

void	*alloc_freed_block(size_t size, int page_size);
void	*alloc_block(size_t size, int page_size);

/* Bonus Calloc */

#endif
