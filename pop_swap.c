#include "monty.h"

/**
 * pop - pop
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap - swap
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
