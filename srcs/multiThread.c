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

void	*counting_routine(void *ptr_data)
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

void	*destroy_routine(void *ptr_data)
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

/*	cree un static int pour compter le nombre de threads qui passe pour pouvoir
faire en sorte que le premier aie trie le node n - 1 puis le 2e n-2 etc et avancer de n a chaque fois */

static t_list *get_unsorted_node(t_reader *data)
{
	t_list		*current;

	current = *(data->h_list);
	pthread_mutex_lock(data->reader_mtx);
	while (current)
	{
		t_bool *sorted = (t_bool *)extract_data_node(current->content, SORTED);
		if (*sorted == FALSE)
		{
			*sorted = TRUE;
			return (pthread_mutex_unlock(data->reader_mtx), current);
		}
		current = current->next;
	}
	pthread_mutex_unlock(data->reader_mtx);
	return (NULL);
}

void	*sorting_routines(void *ptr_data)
{
	t_reader	*data;
	t_list		*current;

	data = (t_reader *)ptr_data;
	while (1)
	{
		current = get_unsorted_node(data);
		if (!current)
			break ;
		t_mtx *mutex = (t_mtx *)extract_data_node(current->content, MTX);
		pthread_mutex_lock(mutex);
		int	*pos = (int *)extract_data_node(current->content, POS);
		int	*count = (int *)extract_data_node(current->content, COUNT);
		ft_quicksort(pos, *count);
		pthread_mutex_unlock(mutex);
	}
	return (NULL);
}

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
	t_mtx *tmp = ft_calloc(1, sizeof(t_mtx));
	if (!tmp)
		return (free(data_threads), free_strs(samples), free(data->threads), 0);
	if (pthread_mutex_init(tmp, NULL) != 0)
		return (free(data_threads), free_strs(samples), free(data->threads), free(tmp), 0);
	i = -1;
	while (++i < data->nb_threads)
		data_threads[i] = init_data_threads(data, samples[i], i, &tmp);
	instantiate_threads(data, data_threads, counting_routine);
	instantiate_threads(data, data_threads, sorting_routines);
	instantiate_threads(data, data_threads, destroy_routine);
	free(data->threads);
	pthread_mutex_destroy(tmp);
	free(tmp);
	tmp = NULL;
	data->threads = NULL;
	free(data_threads);
	free(samples);
	return (1);
}
