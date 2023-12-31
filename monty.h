#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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
 * struct bus - opcode and their functions
 * @file: the opcode
 * @lifi: function
 * @content: pointer to buffer
 * Description: opcode and its function
 */
typedef struct bus
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;
/* function prototypes */

int read_file(char *filename, stack_t **stack);
char *get_line(char* line, int line_number);
typedef void (*instruct_func) (stack_t **stack, unsigned int line_number);
instruct_func get_op_func (char *str);

void _pall(stack_t **head, unsigned int line_number);
void _push(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);

void _add(stack_t **head, unsigned int counter);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);

void addqueue(stack_t **head, int n);
void addnode(stack_t **head, int n);
void print_all(stack_t **head, unsigned int counter);
		
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);


#endif
