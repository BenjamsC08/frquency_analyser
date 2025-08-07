#include "xor_dcode.h"

char	**split_for_threads(t_data *data)
{
	int		l;
	int		n;
	char	*str;
	char	**strs;

	str = data->text + 1;
	l = ft_strlen(str);
	if (l == 0)
		return (NULL);
	if (l < CHAR_MIN_BY_THREADS)
	{
		data->char_by_thread = l;
		data->nb_threads = 1;
	}
	else if (l / CHAR_MIN_BY_THREADS > data->max_threads)
	{
		data->char_by_thread = l / data->max_threads;
		data->nb_threads = data->max_threads;
	}
	else
	{
		data->nb_threads = (l / CHAR_MIN_BY_THREADS);
		data->char_by_thread = (l / data->nb_threads);
	}
	n = 0;
	strs = ft_calloc(data->nb_threads, sizeof(char *));
	if (!strs)
		return (NULL);
	while (n < data->nb_threads)
	{
		strs[n] = ft_strndup(
			(const char *)(str + (data->char_by_thread * n)),
			data->char_by_thread);
		n++;
	}
	return (strs);
}

void	destroy_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	if (!head || !*head)
		return ;
	current = *head;
	next = NULL;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, &free_data_node);
		current = next;
	}
	*head = NULL;
}

void	print_list(t_list **head)
{
	t_list	*current;
	int		count;
	int		*pos;
	int		i;

	current = *head;
	while (current)
	{
		i = -1;
		count = (*(int *)extract_data_node(current->content, COUNT));
		pos = (int *)extract_data_node(current->content, POS);
		ft_dprintf(1, "trigram :'%s', count :'%d', ", (char *)extract_data_node(current->content, TRIGRAM),
			 count);
		while (++i < count)
			ft_dprintf(1, "pos[%d]=%d, ", i, pos[i]);
		ft_dprintf(1,"\n");
		current = current->next;
	}
}
