#include "libft.h"
#include "xor_dcode.h"
#include <stdio.h>

static void explode_sample(t_reader *data, char *sample, t_ulong pos);
static t_list *get_unsorted_node(t_reader *data);

void	*counting_routine(void *ptr_data)
{
	t_reader		*data;
	t_ulong			i;

	data = (t_reader *)ptr_data;
	// if (data->id == 0)
	// 	i = 0;
	// else
	i = -1;
	while (++i < data->length)
	{
		// ft_printf("%strigram : %s\n%s", CYAN, &data->sample[i],RESET);
		if (ft_strlen(&data->sample[i]) <= (t_uint)(data->n_grams - 1))
			break;
		explode_sample(data, &data->sample[i], i);
		// if (!ft_strncmp(&data->sample[i], "f01", 3))
		// 	print_list(data->h_list);
	}
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

static void explode_sample(t_reader *data, char *sample, t_ulong pos)
{
	t_list *current;

	if (!data || !data->h_list)
		return;

	// ft_printf("%strigram : %s\n%s", CYAN, sample, RESET);
	current = *(data->h_list);
	while (current)
	{
		t_mtx *mutex = (t_mtx *)extract_data_node(current->content, MTX);
		if (!mutex)
			return ;
		pthread_mutex_lock(mutex);
		if (!ft_strncmp((char *)extract_data_node(current->content, TRIGRAM), sample, data->n_grams))
		{
			update_data_node(data->id, current->content, ((int)pos  + (data->id * data->char_by_thread)));
			pthread_mutex_unlock(mutex);
			return;
		}
		if (!current->next)
		{
			add_data_node(current, sample, ((int)pos + (data->id * data->char_by_thread)), data->n_grams);
			pthread_mutex_unlock(mutex);
			return;
		}
		pthread_mutex_unlock(mutex);
		current = current->next;
	}
}

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

