#include "monty.h"

/**
 * add - add
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - nothing
 * @stack: stack
 * @line_number: line number
 * Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
