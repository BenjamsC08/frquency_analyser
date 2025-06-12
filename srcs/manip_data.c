#include "xor_dcode.h"

void	free_data(t_data *data)
{
	if (data->trinome)
		free(data->trinome);
	if (data->pos)
		free(data->pos);
	if (data->m_node)
	{
		pthread_mutex_destroy(mtx);
		free(data->m_node);
	}
	free(data);
}

t_data	*create_data(char *str, int pos)
{
	t_data	data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->trinome = ft_strndup(str, 2);
	if (!data->trinome)
		return (free_data(&data), NULL);
	data->pos = ft_calloc(3, sizeof(int));
	if (!data->pos)
		return (free_data(&data), NULL);
	data->pos[0] = pos;
	data->count = 1;
	data->m_node = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->m_node)
		free_data(&data);
	if (pthread_mutex_init(data->node, NULL) != 0)
	{
		free(data->m_node);
		free_data(&data);
	}
	return (&data);
}
