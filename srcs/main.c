#include "xor_dcode.h"


static char	*get_hex(int argc, char **argv) // temp fuc quotes in the next one
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
	return (data);
}

int main(int argc, char **argv)
{
    t_data data;
    t_list *head = NULL;

    if (!init_data(argc, argv, &data))
        return (1);
    head = init_head(data.text);
    if (!head)
        return (free(data.text), 1);
    data.head = &head;
    if (!create_threads(&data))
        return free(data.text), destroy_list(&head), 1;
    // print_list(data.head);
	ft_dprintf(2, "%s%d threads used%s\n", ORANGE, data.nb_threads, RESET);
	ft_dprintf(2, "%sthe size of the list %d nodes%s\n", YELLOW, ft_lstsize(head), RESET);
    destroy_list(data.head);
    free(data.text);
    return (0);
}
