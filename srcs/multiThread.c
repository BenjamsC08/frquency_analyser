#include "xor_dcode.h"

void explode_sample(t_reader *data, char *sample, t_ulong pos)
{
	t_list *current;

	if (!data || !data->h_list)
		return;

	current = *(data->h_list);
	while (current)
	{
		t_mtx *mutex = (t_mtx *)extract_data_node(current->content, MTX);
		if (!mutex)
			return ;
		pthread_mutex_lock(mutex);
		if (!ft_strncmp((char *)extract_data_node(current->content, TRIGRAM), sample, 3))
		{
			update_data_node(current->content, ((int)pos  + (data->id * data->char_by_thread)));
			pthread_mutex_unlock(mutex);
			return;
		}
		if (!current->next)
		{
			add_data_node(current, sample, (pos + (data->id * data->char_by_thread)));
			pthread_mutex_unlock(mutex);
			return;
		}
		pthread_mutex_unlock(mutex);
		current = current->next;
	}
}

void	*counting_routines(void *ptr_data)
{
	t_reader		*data;
	t_ulong			i;
	t_ulong			k;

	data = (t_reader *)ptr_data;
	if (data->id == 0)
		k = 1;
	else
		k = 0;
	i = -1;
	while (++i < data->length - 3)
		explode_sample(data, &data->sample[i], i + k);
	return (NULL);
}

void	*destroy_routines(void *ptr_data)
{
	t_reader	*data;

	if (!ptr_data)
		return (NULL);
	data = (t_reader *)ptr_data;
	if (!data)
		return (NULL);
	if (data->sample)
	{
		free(data->sample);
		data->sample = NULL;
	}
	data->length = 0;
	data->h_list = NULL;
	free(data);
	data = NULL;
	return (NULL);
}

// 
// void	*sorting_routines(void *ptr_data)
// {
//
// 	t_reader	*data;
//
// 	data = (t_reader *)ptr_data;
// }

void	instantiate_threads(t_data *data, t_reader **data_p, void *(*routines)(void *))
{
	int i;

	i = -1;
	while (++i < data->nb_threads)
		pthread_create(&data->threads[i], NULL, routines, data_p[i]);
	i = -1;
	while (++i < data->nb_threads)
		pthread_join(data->threads[i], NULL);
}

int create_threads(t_data *data)
{
	char		**samples;
	t_reader	**data_threads;
	int			i;

	samples = split_for_threads(data);
	if (!samples)
		return (0);
	data_threads = ft_calloc(data->nb_threads, sizeof(t_reader));
	if (!data_threads)
		return (free_strs(samples), 0);
	data->threads = ft_calloc(data->nb_threads, sizeof(pthread_t));
	if (!data->threads)
		return (free(data_threads), free_strs(samples), 0);
	i = -1;
	while (++i < data->nb_threads)
		data_threads[i] = init_data_threads(data, samples[i], i);
	i = -1;
	instantiate_threads(data, data_threads, counting_routines);
	i = -1;
	instantiate_threads(data, data_threads, destroy_routines);
	free(data->threads);
	data->threads = NULL;
	// i = -1;
	// while (++i < data->nb_threads)
	// 	free(data_threads[i]);
	free(data_threads);
	free(samples);
	return (1);
}
