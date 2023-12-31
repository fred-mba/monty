#include "monty.h"
Buffer buf = {NULL, NULL, NULL, 0};
/**
 * main -  monty code interpreter
 * @arg: argument count in the line
 * @argv: monty file location in the buffer
 * Return: 0 upon successfull running of the code
*/
int main(int arg, char *argv[])
{
	char *content;
	FILE *fp;
	size_t buf_size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int arg_count = 0;

	if (arg != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	buf.fp = fp;

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &buf_size, fp);
		buf.content = content;
		arg_count++;

		if (read_line > 0)
		{
			execute(content, &stack, arg_count, fp);
		}
		free(content);
	}
	free_stack(stack);
	fclose(fp);
return (0);
}
