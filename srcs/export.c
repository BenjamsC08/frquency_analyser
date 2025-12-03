#include "freq_a.h"
#include <time.h>
#include <stdio.h>


int export_list(t_list **head)
{
	t_list *current;

	char *str = malloc(256);
	snprintf ( str, 256, "out_%lu.txt", (unsigned long)time(NULL));
	int fd = open(str, O_WRONLY);

	current = (*head)->next;
	while (current)
	{


	}
	return (1);
}
