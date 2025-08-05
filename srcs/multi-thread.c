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

t_reader *init_data_threads(t_data *data, char *str, t_mtx *mtx, int i)
{
    t_reader *thread = ft_calloc(1, sizeof(t_reader));
    if (!thread)
        return (NULL);
    thread->sample = ft_strdup(str);
    if (!thread->sample)
        return free(thread), NULL;
    thread->length = ft_strlen(str);
    thread->h_list = data->head;
	thread->id = i;
	thread->tmp_mtx = mtx;
    return (thread);
}

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

#include <stdio.h>

void	*routines(void *ptr_data)
{
	t_reader		*data;
	t_ulong			i;
	
	data = (t_reader *)ptr_data;

	i = 0;
	while (i < data->length - 3)
	{
		explode_sample(data, &data->sample[i], i);
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
    while (++i < data->nb_threads)
		pthread_join(data->threads[i], NULL);
    free(samples);
    return (1);
}
