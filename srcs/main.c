#include "xor_dcode.h"


static char	*get_hex(int argc, char **argv)
{
	char	*str;
	char	*out;

	str = NULL;
	if (argc == 1)
		return (NULL);
	if (argc >= 2)
		str = ft_unsplit((++argv), 0);
	if (!str)
		return (NULL);
	out = hex_format(str, 0);
	free(str);
	if (!out)
		return (NULL);
	return (out);
}

t_data	*init_data(int argc, char **argv, t_data *data)
{
	//temp a termes l'hex sera pris dans un fgets ou un truc comme ca pas argv donc direct hex_format pas get_hex
	data->text = get_hex(argc, argv);
	if (!data->text)
		return (NULL);
	data->max_threads = 6;
	data->char_by_thread = CHAR_MIN_BY_THREADS;
	data->nb_threads = 1;
	if (pthread_mutex_init(&data->list_mtx, NULL) != 0)
        return (free(data->text), NULL);
	return (data);
}

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

int main(int argc, char **argv)
{
    t_data data;
    t_list *head = NULL;

    if (!init_data(argc, argv, &data))
        return 1;
    head = init_head(data.text);
    if (!head)
        return free(data.text), 1;
    data.head = &head;
    if (!create_threads(&data))
        return free(data.text), destroy_list(&head), 1;
    print_list(data.head);
    destroy_list(data.head);
    pthread_mutex_destroy(&data.list_mtx);
    free(data.text);
    return 0;
}
