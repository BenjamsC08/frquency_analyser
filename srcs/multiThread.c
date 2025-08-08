#include "xor_dcode.h"

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
	t_mtx *mtx_reader = ft_calloc(1, sizeof(t_mtx));
	if (!mtx_reader)
		return (free(data_threads), free_strs(samples), free(data->threads), 0);
	if (pthread_mutex_init(mtx_reader, NULL) != 0)
		return (free(data_threads), free_strs(samples), free(data->threads), free(mtx_reader), 0);
	i = -1;
	while (++i < data->nb_threads)
		data_threads[i] = init_data_threads(data, samples[i], i, &mtx_reader);
	instantiate_threads(data, data_threads, counting_routine);
	instantiate_threads(data, data_threads, sorting_routines);
	instantiate_threads(data, data_threads, destroy_routine);
	free(data->threads);
	pthread_mutex_destroy(mtx_reader);
	free(mtx_reader);
	mtx_reader = NULL;
	data->threads = NULL;
	free(data_threads);
	free(samples);
	return (1);
}
