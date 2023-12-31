#include "monty.h"
/**
  *_sub - sustrat two elements in a stack
  *@head: head pointer to the current node and the result
  *@line_count: line_number
  *Return: void
 */
void _sub(stack_t **head, unsigned int line_count)
{
	stack_t *tp;
	int subs, nodes;

	tp = *head;
	for (nodes = 0; tp != NULL; nodes++)
		tp = tp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	subs = tp->next->data - tp->data;
	tp->next->data = subs;
	*head = tp->next;
	free(tp);
}
