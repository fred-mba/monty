#include "monty.h"
/**
 * _add - add top two elements of the stack.
 * @head: head pointer to the current node and the result
 * @line_count: line_number
 * Return: void
*/
void _add(stack_t **head, unsigned int line_count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	aux = ptr->data + ptr->next->data;
	ptr->next->data = aux;
	*head = ptr->next;
	free(ptr);
}
