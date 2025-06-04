#include "xor_dcode.h"

#define CHAR_BY_THREADS 1024

char	**split_for_threads(char *str, t_data *data)
{
	int		l;
	int		n;
	char	**strs;

	l = ft_strlen(str);
	if (l / CHAR_BY_THREADS > data->max_threads)
	{
		data->char_by_thread = l / data->max_threads;
		data->nb_threads = data->max_threads;
	}
	else
	{
		data->nb_threads = (l / CHAR_BY_THREADS);
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
