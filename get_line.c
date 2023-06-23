#include "main.h"

char *parse_line(char *line, int line_number)
{
	char *opcode, *push, *arg;

	push = "push";
	opcode = strtok(line, "\n ");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (is_number(arg) == 1 && arg != NULL)
		{
			global_variables.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}

int is_number(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
