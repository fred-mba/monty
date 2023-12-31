#include "monty.h"
/**
 *addnode - adds node to the stack
 * @head: pointer to the head of old and new formed linked list
 * @data: value to be added in the stack
*/
void addnode(stack_t **head, int data)
{
	stack_t *newNode, *ptr;

	ptr = *head;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (ptr)
	{
		ptr->prev = newNode;
		newNode->data = data;
		newNode->next = *head;
		newNode->prev = NULL;
		*head = newNode;
	}
}
