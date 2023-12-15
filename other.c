#include "monty.h"
/**
 * pchar - pchar
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}
/**
 * pstr - pstr
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;
	while (!current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		if (current->n == '\0')
			break;
		current = current->next;
	}
	putchar('\n');
}
/**
 * rotl - rotl
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;
		last->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->next = NULL;
		last->next->prev = last;
	}
}
/**
 * rotr - rotr
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
