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
	data->count = 1;
	data->pos = ft_calloc(1, sizeof(int));
	if (!data->pos)
		return (free_data(&data), NULL);
	data->pos[0] = pos;
	data->m_node = ft_calloc(1, sizeof(t_mtx));
	if (!data->m_node)
		free_data(&data);
	if (pthread_mutex_init(data->node, NULL) != 0)
	{
		free(data->m_node);
		free_data(&data);
	}
	return (&data);
}

void	update_data(t_data *data, int pos)
{
	int	*new_pos;
	int	i;

	data->count++;
	new_pos = ft_calloc(data->count, sizeof(int));
	if (!new_pos)
		return ;
	i = -1;
	while (++i < (data->count - 1))
		new_pos[i] = data->pos[i];
	new_pos[i] = pos;
	free(data->pos);
	data->pos = new_pos;
}

void	*extract_data(void *ptr_data, char type)
{
	t_data	*data;

	data = (t_data *)ptr_data;
	if (type == TRINOME)
		return (data->trinome);
	if (type == POS)
		return (data->pos);
	if (type == MTX)
		return (data->m_node);
	if (type == COUNT)
		return (data->count);

}
