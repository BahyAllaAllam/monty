#include "monty.h"
/**
 * free_stack - free_stack
 * @stack: stack
 * Return: Nothing
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
/**
 * handle_unknown_instruction - handle_unknown_instruction
 * @line_number: line_number
 * @opcode: *opcode
 * Return: Nothing
*/
void handle_unknown_instruction(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}
/**
 * excute - excution of the functions
 * @file: file
 * @stack: stack
 * @instructions: array of functions
 * Return: Nothing
*/
void excute(FILE *file, stack_t **stack, instruction_t *instructions)
{
	char line[BUFSIZ], *opcode, *argument;
	unsigned int line_number = 0;
	int i;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && strcmp(opcode, "\n") != 0)
		{
			argument = strtok(NULL, " \t\n");

			i = 0;

			if (strcmp(opcode, "push") == 0)
			{
				push(stack, line_number, argument);
				continue;
			}
			while (instructions[i].opcode != NULL)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(stack, line_number);
					break;
				}
				i++;
			}
			if (instructions[i].opcode == NULL)
			{
				handle_unknown_instruction(line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
}
/**
 * read_and_parse_file - read_and_parse_file
 * @filename: filename
 * @instructions: array of functions
 * Return: int
*/
int read_and_parse_file(const char *filename, instruction_t *instructions)
{
	FILE *file = fopen(filename, "r");
	stack_t *stack;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	stack = NULL;

	excute(file, &stack, instructions);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: integer
*/
int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"pall", &pall},
		{"add", &add},
		{"pint", &pint},
		{"swap", &swap},
		{"pop", &pop},
		{"nop", &nop},
		{"mod", &mod},
		{"sub", &sub},
		{"div", &divide},
		{"mul", &mul},
		{"rotr", &rotr},
		{"rotl", &rotl},
		{"pstr", &pstr},
		{"pchar", &pchar},
		{NULL, NULL}
	};

	int exit_status;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	exit_status = read_and_parse_file(argv[1], instructions);
	return (exit_status);
}
