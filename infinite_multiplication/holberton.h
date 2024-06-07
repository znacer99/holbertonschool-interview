#ifndef INF_MUL_H
#define INF_MUL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct add_s - Node in the linked list of additions
 *
 * @n_add: Pointer to an addition representation
 * @n_dig: Real space that addtion takes
 * @len_r: Total space to save the addition
 * @next: Pointer to the next addition
 */
typedef struct add_s
{
	char *n_add;
	int n_dig;
	int len_r;
	struct add_s *next;
} add_t;

int _putchar(char c);
#endif
