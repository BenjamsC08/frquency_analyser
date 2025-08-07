#include "xor_dcode.h"

t_list *init_head(char *tri)
{
    t_data_node *data;

    data = ft_calloc(1, sizeof(t_data_node));
    if (!data)
        return (NULL);
    data->trigram = ft_strndup(tri, 3);
    if (!data->trigram)
        return (free(data), NULL);
    data->count = 1;
    data->mtx_node = ft_calloc(1, sizeof(t_mtx));
    if (!data->mtx_node)
        return (free(data->trigram), free(data), NULL);
    if (pthread_mutex_init(data->mtx_node, NULL) != 0)
        return (free_data_node(data), NULL);
    data->pos = ft_calloc(1, sizeof(int));
    if (!data->pos)
        return (free_data_node(data), NULL);
    data->pos[0] = 0;
    return (ft_lstnew(data));
}

t_reader *init_data_threads(t_data *data, char *str, t_mtx *mtx, int i)
{
    t_reader *thread = ft_calloc(1, sizeof(t_reader));
    if (!thread)
        return (NULL);
    thread->sample = ft_strdup(str);
    if (!thread->sample)
        return free(thread), free(str), NULL;
    thread->length = ft_strlen(str);
	free(str);
    thread->h_list = data->head;
	thread->id = i;
	thread->tmp_mtx = mtx;
    return (thread);
}
