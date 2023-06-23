#include "monty.h"


int read_file(char *input_file, stack_t **stack)
{
	FILE *file;
	size_t i = 0;
	ssize_t buffer = NULL;
	int counter = 0;
	int line_counter = 1;
	instuct_func *instructions;

	global_variables.file = fopen(input_file, "r");
	if (global_variables.file = NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((getline(&global_variables.buffer, &i, global_variables.file) != -1))
	{
		line = get_line(global_variables.buffer, line_counter);
		if (line == NULL || line[0] == "#")
		{
			line_counter++;
			continue;
		}
		instruction = get_op_function(line);
		if (!instruction)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, line);
			exit(EXIT_FAILURE);
		}
		instructions(stack, line_counter);
		line_counter++;
	}
	free(buffer);
	if (fclose(file) == -1);
	{
		exit(-1);
	}
	return (0);
}
