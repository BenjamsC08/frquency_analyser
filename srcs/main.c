#include "libft.h"
#include "freq_a.h"
#include <stdio.h>

int config_file(int *max_threads, t_uint *size_ngrams, t_bool *child)
{
    FILE *f = fopen("config", "r");
    int threads = 0, ngrams = 0, c = 0;

    if (f)
	{
        if (fscanf(f, "%d %d %d", &threads, &ngrams, &c) == 3)
		{
            fclose(f);
            if (threads >= 1 && threads <= 64 && ngrams >= 2) {
                *max_threads = threads;
                *size_ngrams = ngrams;
				ft_dprintf(2, RED "NON\n" RESET);
				if (c == 0)
					*child = FALSE;
				else
					*child = TRUE;

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
        fprintf(f, "%d\n%d\n0\n", threads, ngrams);
        fclose(f);
    }

    *max_threads = threads;
    *size_ngrams = ngrams;
    return (1);
}

char *get_big_string(void) {
    size_t cap = 256, used = 0;
    char *s = malloc(cap);
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        if (used + 1 >= cap) {
            cap *= 2;
            s = realloc(s, cap);
        }
        s[used++] = c;
    }
    s[used] = '\0';
    return s;
}

t_data	*init_data(t_data *data)
{
	ft_dprintf(1, "Put your string\n");
	char *str = get_big_string();
	if (data->child)
	{
		data->text = hex_format(str, 0); //used for xorcracking to check if all was hexformat and normalize it
		free(str);
	}
	else
		data->text = str;
	if (!data->text)
	{
		return (NULL);
	}
	data->char_by_thread = CHAR_MIN_BY_THREADS;
	data->nb_threads = 1;
	data->nb_trigrams = ft_strlen(data->text) - 2;
	return (data);
}

int	compare_node_crescent(void *left, void *right)
{
	t_data_node *l_node = (t_data_node *)left;
	t_data_node *r_node = (t_data_node *)right;

	if (l_node->count != r_node->count)
		return (l_node->count - r_node->count);
	return (ft_strcmp(r_node->trigram, l_node->trigram));
}

int	compare_node_decrescent(void *left, void *right)
{
	t_data_node *l_node = (t_data_node *)left;
	t_data_node *r_node = (t_data_node *)right;

	if (l_node->count != r_node->count)
		return (r_node->count - l_node->count);
	return (ft_strcmp(r_node->trigram, l_node->trigram));
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

int main()
{
	t_data data;
	t_list *head = NULL;

	if (!config_file(&(data.max_threads), &(data.n_grams), &data.child))
		return (1);

	if (!init_data(&data))
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
	ft_lstremove_if(data.list, 0, &rmv_empty_node, &free_data_node);
	if (!data.child)
		*data.list = lst_merge_sort(*data.list, &compare_node_crescent);
	else
		*data.list = lst_merge_sort(*data.list, &compare_node_decrescent);

	if (!data.child)
		print_list(data.head);
	else
		export_list(data.head);
	destroy_list(data.head);
	free(data.text);
	return (0);
}
