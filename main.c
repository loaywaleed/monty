#include "main.h"

/**
 * main - entry point
 * argc: arguments number
 * argv: arguments themselves
 * Return: 0 for success
 */

int main(int argc, char** argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
}

