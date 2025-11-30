#include "libft.h"
#include "xor_dcode.h"
#include "xor_def.h"
#include <stdio.h>


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

int config_file(int *max_threads, t_uint *size_ngrams)
{
    FILE *f = fopen("config", "r");
    int threads = 0, ngrams = 0;

    if (f)
	{
        if (fscanf(f, "%d %d", &threads, &ngrams) == 2)
		{
            fclose(f);
            if (threads >= 1 && threads <= 64 && ngrams >= 2) {
                *max_threads = threads;
                *size_ngrams = ngrams;
                return (1);
            }
        }
        fclose(f);
    }
    ft_dprintf(1, "No valid configuration found. Entering interactive setup.\n");

    while (1)
	{
        ft_dprintf(1, "Max thread (1-64) [<= nproc]:\n");
        if (scanf("%d", &threads) == 1 && threads >= 1 && threads <= 64)
            break;
        ft_dprintf(1, "Invalid thread count.\n");
        while (getchar() != '\n');
    }

    while (1) {
        ft_dprintf(1, "Size of ngrams (min 2, max INT_MAX):\n");
        if (scanf("%d", &ngrams) == 1 && ngrams >= 2)
            break;
        ft_dprintf(1, "Invalid size.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    f = fopen("config", "w");
    if (f)
	{
        fprintf(f, "%d\n%d\n", threads, ngrams);
        fclose(f);
    }

    *max_threads = threads;
    *size_ngrams = ngrams;
    return (1);
}

t_data	*init_data(int argc, char **argv, t_data *data)
{
	data->text = get_hex(argc, argv);
	if (!data->text)
		return (NULL);
	data->char_by_thread = CHAR_MIN_BY_THREADS;
	data->nb_threads = 1;
	data->nb_trigrams = ft_strlen(data->text) - 2;
	return (data);
}

int	compare_node(void *left, void *right)
{
	t_data_node *l_node = (t_data_node *)left;
	t_data_node *r_node = (t_data_node *)right;

	if (l_node->count - r_node->count != 0)
		return (r_node->count - l_node->count);
	else
		return (ft_strcmp(l_node->trigram, r_node->trigram));
}

int rmv_empty_node(void *content, void *ref, size_t size)
{
	(void)ref;
	(void)size;
	t_data_node *node = (t_data_node *)content;

	if (node->count == 0)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_data data;
	t_list *head = NULL;

	if (!config_file(&(data.max_threads), &(data.n_grams)))
		return (1);

	if (!init_data(argc, argv, &data))
		return (1);
	head = init_head(&data);
	if (!head)
		return (free(data.text), 1);
	data.head = &head;
	(*(data.head))->next = start_list(&data);
	data.list = &((*(data.head))->next);
	if (!data.list)
		return free(data.text), destroy_list(&head), 1;
	if (!create_threads(&data))
		return free(data.text), destroy_list(&head), 1;
	lst_merge_sort(*data.head, &compare_node);
	ft_lstremove_if(data.list, 0, &rmv_empty_node, &free_data_node);

	int l = ft_strlen(data.text);
	ft_dprintf(1, "%slength of the sample %d, so %d trigrams\n%s", CYAN, l, l-2, RESET );
	ft_dprintf(1, "%s%d threads used%s\n", CYAN, data.nb_threads, RESET);
	ft_dprintf(1, "%s%d nodes%s\n", CYAN, ft_lstsize(head), RESET);
	print_list(data.list);
	destroy_list(data.head);
	free(data.text);
	return (0);
}
