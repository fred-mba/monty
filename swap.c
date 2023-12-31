#include "monty.h"
/**
 * _swap - adds top two elements of the stack.
 * @head: head of stack
 * @line_count: line_number
 * Return: void
*/
void _swap(stack_t **head, unsigned int line_count)
{
	stack_t *ptr;
	int len = 0, aux;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	aux = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = aux;
}
