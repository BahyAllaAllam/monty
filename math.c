#include "monty.h"
/**
 * sub - subtracts
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->next;
		temp->n -= (*stack)->n;
		*stack = temp;
		temp->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * div - division
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->next;
		temp->n /= (*stack)->n;
		*stack = temp;
		temp->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - mul
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->next;
		temp->n *= (*stack)->n;
		*stack = temp;
		temp->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - calculates the remainder
 * @stack: stack
 * @line_number: line_number
 * Return: Nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->next;
		temp->n %= (*stack)->n;
		*stack = temp;
		temp->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
