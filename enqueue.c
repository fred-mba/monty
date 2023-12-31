#include "monty.h"
/**
*_queue - change instruction to queue(LIFO)
*@head: head pointer
*@line_count: queue number is 1
*Return: void
*/
void _queue(stack_t **head, unsigned int line_count)
{
	(void)head;
	(void)line_count;
	buf.change = 1;
}
/**
 *enqueue - adds node to the end of the stack
 *@head: head pointer
 *@data: new value to be added
 *Return: void
 */
void enqueue(stack_t **head, int data)
{
	stack_t *newNode, *top;

	top = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
	}
	newNode->data = data;
	newNode->next = NULL;
	if (top)
	{
		while (top->next)
			top = top->next;
	}
	if (!top)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		top->next = newNode;
		newNode->prev = top;
	}
}
