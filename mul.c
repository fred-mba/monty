#include "monty.h"
/**
 *_mul - multiplies the second top element of the stack with
 *	the top element of the stack.
 *@head: head pointer to the current node and the result
 *@line_count: line number
 *Return: void
 */
void _mul(stack_t **head, unsigned int line_count)
{
	stack_t *ptr;
	int nodes = 0, mult;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		nodes++;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	mult = ptr->next->data * ptr->data;
	ptr->next->data = mult;
	*head = ptr->next;
	free(ptr);
}
