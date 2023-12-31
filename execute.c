#include "monty.h"
/**
 *execute - executes the opcodes
 *@content: arguments passed in the buffer
 *@stack: pointer to head node on stack
 *@line_count: line count: 0 for stack and 1 for queue
 *@fp: file pointer
 *Return: 1 if wrong opcode is used
 * When the first non-space character of a line is #,
 *	treat this line as a comment (don’t do anything).
*/
int execute(char *content, stack_t **stack, unsigned int line_count, FILE *fp)
{
	instruction_t opc[] = {
				{"push", _push}, {"pall", _pall}, {"add", _add},
				{"swap", _swap},
				{"pint", _pall},
				{"pop", _pop},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}};
	unsigned int indx = 0;
	char *opc_ptr;

	opc_ptr = strtok(content, " \n\t");
	if (opc_ptr && opc_ptr[0] == '#')
		return (0);
	buf.arg = strtok(NULL, " \n\t");
	while (opc[indx].opcode && opc_ptr)
	{
		if (strcmp(opc_ptr, opc[indx].opcode) == 0)
		{
			opc[indx].f(stack, line_count);
			return (0); }
		indx++; }
	if (opc_ptr && opc[indx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opc_ptr);
		fclose(fp);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
