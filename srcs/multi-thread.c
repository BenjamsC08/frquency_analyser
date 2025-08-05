#include "xor_dcode.h"

char	**split_for_threads(t_data *data)
{
	int		l;
	int		n;
	char	*str;
	char	**strs;

	str = data->text + 1;
	l = ft_strlen(str);
	ft_fprintf(2, "%sDEBUG l:'%d', str:'%s'%s\n", ORANGE, l, str, RESET);
	if (l == 0)
	{
		ft_fprintf(2, "%sDEBUG What%s\n", GREEN, RESET);
		return (NULL);
	}
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
	ft_fprintf(2, "%sDEBUG l:'%d', str:'%s'%s\n", PURPLE, l, str, RESET);
	return (strs);
}

t_reader *init_data_threads(t_data *data, char *str)
{
    t_reader *thread = ft_calloc(1, sizeof(t_reader));
    if (!thread)
        return (NULL);
    thread->sample = ft_strdup(str);
    if (!thread->sample)
        return free(thread), NULL;
    thread->length = ft_strlen(str);
    thread->h_list = data->head;
    return (thread);
}

// void	explode_sample(t_reader *data, char *sample, int pos)
// {
// 	t_list		*current;
//
// 	current = *(data->h_list);
// 	while (current)
// 	{
// 		pthread_mutex_lock((t_mtx *)(extract_data_node(current->content, MTX)));
// 		if (!ft_strncmp(((char *)(extract_data_node(current->content, TRIGRAM))), sample, 3))
// 			break ;
// 		pthread_mutex_unlock((t_mtx *)(extract_data_node(current->content, MTX)));
// 		current = current->next;
// 	}
// 	if (current)
// 	{
// 		update_data_node(current->content, pos);
// 		pthread_mutex_unlock((t_mtx *)(extract_data_node(current->content, MTX)));
// 	}
// 	else
// 		add_data_node(data->h_list, sample, pos);
// }

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
            update_data_node(current->content, (int)pos);
            pthread_mutex_unlock(mutex);
            return;
        }
        pthread_mutex_unlock(mutex);
        current = current->next;
		ft_fprintf(2, "%sDEBUG palapls\n", YELLOW, RESET);
    }
	ft_fprintf(2, "%sDEBUG bien ICI\n", GREEN, RESET);

    pthread_mutex_lock(&((t_data *)data->h_list)->list_mtx);
	ft_fprintf(2, "%sDEBUG tu rentre pas\n", YELLOW, RESET);
    add_data_node(data->h_list, sample, pos);
    pthread_mutex_unlock(&((t_data *)data->h_list)->list_mtx);
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

	i = 0;
	data = (t_reader *)ptr_data;
	while (i < data->length - 3)
	{
		explode_sample(data, &data->sample[i], i);
		i++;
		ft_fprintf(2, "%sDEBUG pq la i:'%d'\n", YELLOW, i, RESET);
	}
	ft_fprintf(2, "%sDEBUG ICI\n", BLUE, RESET);
	destroy_reader(data);
	return (NULL);
}

int create_threads(t_data *data)
{
    char **samples;
    int i;
    t_reader *data_p;

    samples = split_for_threads(data);
    if (!samples)
        return (0);
    data->threads = ft_calloc(data->nb_threads, sizeof(pthread_t));
    if (!data->threads)
        return (0);
    i = -1;
    while (++i < data->nb_threads)
    {
        data_p = init_data_threads(data, samples[i]);
        pthread_create(&data->threads[i], NULL, routines, data_p);
    }
	ft_fprintf(2, "%sDEBUG LA\n", YELLOW, RESET);
    i = -1;
    while (++i < data->nb_threads)
	{
		pthread_join(data->threads[i], NULL);
	}
	ft_fprintf(2, "%sDEBUG maybe\n", PINK, RESET);
    free_strs(samples);
    return (1);
}
