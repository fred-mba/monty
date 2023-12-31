#include "monty.h"
/**
 * _pall - prints all the values on the stack,
 *          starting from the top of the stack
 * @head: head pointer to current and newly created
 * @line_count: counts the line number
 * Return: void
*/
void _pall(stack_t **head, unsigned int line_count)
{
	stack_t *pt;
	(void)line_count;

	pt = *head;
	if (pt == NULL)
		return;

	while (pt)
	{
		printf("%d\n", pt->data);
		pt = pt->next;
	}
}
