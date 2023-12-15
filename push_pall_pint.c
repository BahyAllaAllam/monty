#include "monty.h"

/**
 * push - push
 * @stack: stack
 * @line_number: line_number
 * @argument: argument
 * Return: Nothing
*/
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *new_node;
	int value;

	if (argument == NULL || !(*argument >= '0' && *argument <= '9'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - void pall
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - void pint
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
