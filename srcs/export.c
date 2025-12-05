#include "freq_a.h"
#include "freqa_def.h"
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>


int export_list(t_list **head)
{
	t_list *current;

	char str[256];
	mkdir("result", 0777);
	snprintf ( str, 256, "result/out_%lu.txt", (unsigned long)time(NULL));
	int fd = open(str, O_WRONLY | O_CREAT);
	if (fd == -1)
		return (0);

	current = (*head)->next;
	int count = 0;
	char line[256];
	while (current)
	{
		int tmp = *((int*)(extract_data_node(current->content, COUNT)));
		if (count != tmp)
		{
			if (count)
				write(fd, "\n", 1);
			count = tmp;
			snprintf(line, 256, "count %d:\n", count);
			write(fd, line, ft_strlen(line));
		}
		snprintf(line, 256, "\t \"%s\":\n", (char *)extract_data_node(current->content, TRIGRAM));
		write(fd, line, ft_strlen(line));
		int *pos = (int *)extract_data_node(current->content, POS);
		write(fd, "\t\t{", 3);
		for (int i=0; i < count; i++)
		{
			if (i < count - 1)
				snprintf(line, 256, "%d, ", pos[i]);
			else
				snprintf(line, 256, "%d}", pos[i]);
			write(fd, line, ft_strlen(line));
		}
		write(fd, "\n", 1);
		current = current->next;
	}
	close(fd);
	ft_printf("check : %s\n", str);
	return (1);
}
