
#include "xor_dcode.h"

void	create_data_node(t_list **head, char *trinome)
{
	t_data_node	data;
	t_list		*new;

	if (!pthread_mutex_init(&data.mtx_node))
		return (NULL);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data.trinome = ft_strdup(trinome);
	if (!data.trinome)
		return (free(data), NULL);
	data.count = 1;
	new = ft_lstnew(&data);
	ft_lstadd_back(head, new);
}

void	destroy_data_node(t_list **head)
{
	t_data	*data;
	t_list	*new;

	new = ft_lstlast(head);
	data = (t_data_node *)new->content;
	data->count = -1;
	pthread_mutex_destroy(data->mtx_node)
	free(data->trinome);
	data->trinome = NULL;
	free(data);
	free(new);
}
