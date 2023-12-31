#include "monty.h"
/**
 *_div - divides the second top element of the stack
 *	by the top element of the stack.
 *@head: head pointer to the current node and the result
 *@line_count: line number
 *Return: void
 */
void _div(stack_t **head, unsigned int line_count)
{
	stack_t *tp;
	int nodes, div;

	for (nodes = 0; tp != NULL; nodes++)
		tp = tp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	div = tp->next->data / tp->data;
	tp->next->data = div;
	*head = tp->next;
	free(tp);
}
