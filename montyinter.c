#include "monty.h"

/**
 * _isdigit - checks if a string is a number
 * @c: character to check
 * Return: 1 if its a number, 0 otherwise
*/
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * push - function to add a new element to the top of the stack
 * @stack: pointer to pointer to the first element on the stack
 * @line_number: number of the current line
 * Return: 0 if the element is successfully added to the stack
*/
int push(stack_t **stack, unsigned int line_number)
{
	char *numchar = NULL;
	int num = 0;
	stack_t *new_node = NULL;

	numchar = strtok(NULL, " \t\n");

	if (numchar == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; numchar[i] != '\0'; i++)
	{
		if (!_isdigit(numchar[i]) && numchar[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(numchar);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	return (0);
}