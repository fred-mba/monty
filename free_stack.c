#include "monty.h"
/**
 * free_stack - frees the memory of a doubly linked list
 * @head: pointer to the head node
*/
void free_stack(stack_t *head)
{
	stack_t *ptr;

	ptr = head;
	while (ptr)
	{
		ptr = head->next;
		free(ptr);
		head = ptr;
	}
}
