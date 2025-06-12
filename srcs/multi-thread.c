#include "xor_dcode.h"


char	**split_for_threads(t_data *data)
{
	int		l;
	int		n;
	char	*str;
	char	**strs;

	str = data->text;
	l = ft_strlen(str);
	if (l / CHAR_MIN_BY_THREADS > data->max_threads)
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
	while (n < data->nb_threads)
	{
		strs[n] = ft_strndup(
			(const char *)(str + (data->char_by_thread * n)),
			data->char_by_thread);
		n++;
	}
	return (strs);
}

int	create_threads(t_data *data)
{
	char		**samples;
	int			i;
	t_reader	data_p;

	samples = split_for_threads(data);
	i = -1;
	data->threads = ft_calloc(sizeof(pthread_t), data->nb_threads);
	if (!data->threads)
		return (0);
	while (++i < data->nb_threads)
	{
		data_p = init_data_threads(data, samples, i);
		pthread_create(data->threads[i], NULL, routines, data_p); //data_p est a free dans les threads peut etre utiliser une var global dans le cas ou un seul echou pour ne pas avoir de leak
	}
}


	{
		if (pthread_create(&obs->philos[i], NULL, routines, (void *)&(*ptr_ps)[i]) != 0)
			return (t2f_mutex(obs, NULL), 0);
	}
