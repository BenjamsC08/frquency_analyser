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

void	destroy_reader(t_reader *data)
{
	if (data->sample)
		free(data->sample);
	data->length = 0;
	data->h_list = NULL;
	free(data);
	data = NULL;
}

void	*routines(void *ptr_data)
{
	t_reader		*data;
	t_ulong			i;
	t_ulong			k;
	
	data = (t_reader *)ptr_data;
	if (data->id == 0)
		k = 1;
	else
		k = 0;
	i = 0;
	while (i < data->length - 3)
	{
		explode_sample(data, &data->sample[i], i + k);
		i++;
	}
	destroy_reader(data);
	return (NULL);
}

int create_threads(t_data *data)
{
    char **samples;
    int i;
    t_reader *data_p;
	t_mtx	  tmp;

    samples = split_for_threads(data);
    if (!samples)
		return (0);
    data->threads = ft_calloc(data->nb_threads, sizeof(pthread_t));
    if (!data->threads)
        return (free_strs(samples), 0);
    i = -1;
	pthread_mutex_init(&tmp, NULL);
    while (++i < data->nb_threads)
    {
        data_p = init_data_threads(data, samples[i], &tmp, i);
		data_p->char_by_thread = data->char_by_thread;
        pthread_create(&data->threads[i], NULL, routines, data_p);
    }
    i = -1;
	ft_dprintf(2, "%suse %d threads%s\n", ORANGE, data->nb_threads, RESET);
    while (++i < data->nb_threads)
		pthread_join(data->threads[i], NULL);
    free(samples);
    return (1);
}
