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
#include <string.h>
#include <pthread.h>
#include "list.h"

/*
** Memory allocation
*/

void	*malloc(size_t size);

/*
** Free memory
*/

void	free(void *ptr);

/*
** Re alloc memory
*/

void	*realloc(void *ptr, size_t size);

/*
** Basic allocation function
*/

void	*alloc_freed_block(size_t size);
void	*alloc_block(size_t size, int page_size);

/*
** Tools functions for memory block
*/

block_t	*get_struct_ptr(void *mem_member);

/*
** Bonus Calloc
*/

void	*calloc(size_t, size_t);

#endif
