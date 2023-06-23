#include "main.h"
/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *x;

	x = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (x)
	{
		while (x->next)
			x = x->next;
	}
	if (!x)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		x->next = new_node;
		new_node->prev = x;
	}
}

/**
 * _stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *x;

	x = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (x)
		x->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * print_all - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void print_all(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
