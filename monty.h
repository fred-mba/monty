#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @data: integer input value
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	struct stack_s *prev;
	struct stack_s *next;
	int data;
} stack_t;

/**
 * struct buffer - defines the structure of buffer to hold
 *		opcodes and instructions
 * @arg: argument value
 * @fp: pointer to monty file
 * @content: pointer to line content
 * @change: change instruction to stack or queue
*/
typedef struct
{
	char *arg;
	FILE *fp;
	char *content;
	int change;
} Buffer;
extern Buffer buf;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int main(int arg, char *argv[]);
void _push(stack_t **head, unsigned int line_count);
int execute(char *content, stack_t **stack, unsigned int line, FILE *fp);
void free_stack(stack_t *head);
void addnode(stack_t **head, int data);
void _add(stack_t **head, unsigned int line_count);
void _pall(stack_t **head, unsigned int line_count);
void _swap(stack_t **head, unsigned int line_count);
void _pop(stack_t **head, unsigned int line_count);
void _nop(stack_t **head, unsigned int line_count);
void _sub(stack_t **head, unsigned int line_count);
void _div(stack_t **head, unsigned int line_count);
void _mul(stack_t **head, unsigned int line_count);
void _mod(stack_t **head, unsigned int line_count);
void enqueue(stack_t **head, int data);
void _queue(stack_t **head, unsigned int line_count);
void _stack(stack_t **head, unsigned int line_count);
#endif
