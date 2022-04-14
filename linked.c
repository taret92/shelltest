#include "main.h"
/**
 * add - add
 * @head: head of the list
 * @arg: arguments
 * Return: node
 */
args_t *add(args_t **head, char *arg)
{
	args_t *node, *aux;

	aux = *head;

	if (arg == NULL)
	{
		return (NULL);
	}

	node = malloc(sizeof(args_t));

	if (node == NULL)
		return (NULL);

	node->arg = strdup(arg);
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	return (node);
}

/**
 * size_t count - count arguments
 * @head: head of the list
 * Return: i
 */
size_t count(args_t *head)
		{

			int i;

		for (i = 0; head; i++)
		{
			printf ("arguments -> [%s]", head->arg);
			head = head->next;
		}
		return (i);
		}

/**
 * transform - transform
 * @head: head of the list
 * Return: arguments
 */
char **transform(args_t **head)
{
	int i;
	args_t *h = *head;
	char **arguments;

	for (i = 0; h; i++)
		h = h->next;

	arguments = malloc((i + 1) * sizeof(char *));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		arguments[i] = h->arg;
	arguments[i] = NULL;

	return (arguments);
}
