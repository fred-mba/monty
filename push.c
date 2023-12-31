
#include "monty.h"
/**
 * _push - add a node to the stack
 * @head: head pointer
 * @line_count: line count
 * Return: void
*/
void _push(stack_t **head, unsigned int line_count)
{
	int j, indx = 0, flag = 0;

	if (buf.arg)
	{
		if (buf.arg[0] == '-')
			indx++;
		for (; buf.arg[indx] != '\0'; indx++)
		{
			if (buf.arg[indx] > 57 || buf.arg[indx] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_count);
			fclose(buf.fp);
			free(buf.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		fclose(buf.fp);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	j = atoi(buf.arg);

	if (buf.change == 0)
		addnode(head, j);

	else
		enqueue(head, j);
}
