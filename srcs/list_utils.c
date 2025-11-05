#include "xor_dcode.h"


/* need to be changed lost a lot of trigrams depends on how many threads because
*
*
*
*	if thread 1 have -	123
*	if thread 2 have -	456
*	if thread 3 have -	789	  (like they did actually)
*
*	i lost trigrams : {234, 567}
*
*	each trigrams n > 0 need to have the two last char of the last thread
*
*/

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
	int f = 0;
	while (n < data->nb_threads)
	{
		if (n + 1 == data->nb_threads)
		{
			strs[n] = ft_strndup(
				(const char *)((str - f) + (data->char_by_thread * n)),
				ft_strlen((str + (data->char_by_thread * n))) + f);
		}
		else
		{
			strs[n] = ft_strndup(
				(const char *)((str - f) + (data->char_by_thread * n)),
				data->char_by_thread + f);
		}
		n++;
		f = 2;
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

	current = *head;
	while (current)
	{
		count = (*(int *)extract_data_node(current->content, COUNT));
		pos = (int *)extract_data_node(current->content, POS);
		ft_dprintf(1, "trigram :'%s%s%s', count :'%s%d%s'",
			 GREEN, (char *)extract_data_node(current->content, TRIGRAM), RESET,
			 YELLOW, count, RESET);
		if (DISP == 2)
		{
			ft_dprintf(1, ", pos:[" );
			int i = -1;
			while (++i < count)
				ft_dprintf(1, "%d, ", pos[i]);
			ft_dprintf(1, "]");
		}
		ft_dprintf(1, "\n");
		current = current->next;
	}
}
