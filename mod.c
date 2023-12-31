#include "monty.h"
/**
 *_mod - computes the rest of the division of the second top
 *	element of the stack by the top element of the stack.
 *@head: head pointer to the current node and the result
 *@line_count: line number
 *Return: void
 */
void _mod(stack_t **head, unsigned int line_count)
{
	stack_t *top;
	int nodes = 0, mod;

	top = *head;
	while (top)
	{
		top = top->next;
		nodes++;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->data == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mod = top->next->data % top->data;
	top->next->data = mod;
	*head = top->next;
	free(top);
}
