#include "monty.h"
/**
 * _pop - prints the top element
 * @head: head of stack
 * @line_count: line_number
 * Return: void
*/
void _pop(stack_t **head, unsigned int line_count)
{
	stack_t *ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	free(ptr);
}
