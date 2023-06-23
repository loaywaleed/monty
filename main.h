#ifndef MAIN_H
#define MAIN_H

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

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

/**
 * struct global_struct - opcode and their functions
 * @file: the opcode
 * @handle_opcode: function to handle the opcode
 * @buffer: pointer to buffer
 * Description: opcode and its function
 */
struct global_struct
{
	FILE *file;
	int handle_opcode;
	char *buffer;
	stack_t **stack;
}

extern global_struct global_variables;
/* function prototypes */

int read_file(char *filename, stack_t **stack);
char *get_line(char* line, int line_number);
typedef void (*instruction) (stack_t **stack, unsigned int line_number);
instruction get_op_func (char *str);

int _pall(stack_t **stack, unsigned int line_number);
int _push(stack_t **stack, unsigned int line_number);
int _pint(stack_t **stack, unsigned int line_number);
int _pop(stack_t **stack, unsigned int line_number);
int _swap(stack_t **stack, unsigned int line_number);
int _nop(stack_t **stack, unsigned int line_number);


		
		


#endif
