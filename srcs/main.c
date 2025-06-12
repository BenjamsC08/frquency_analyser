#include "xor_dcode.h"


//temp a termes l'hex sera pris dans un fgets ou un truc comme ca
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

t_data	*init_data(int argc, char **argv)
{
	t_data data;
	// after doing with argv but actually arv is the input of trinomes
	data->text = get_hex(argc, argv);
	if (!data->text)
		return (NULL);
	data->max_threads = 6;
	data->char_by_thread = CHAR_MIN_BY_THREADS;
	data->nb_threads = 1;
}

t_list	*init_head()
{
	t_data_node	data;
	//degeulasse mais tqt
	data->trinome = NULL;
	data->count = -1;
	data->m_node = NULL;
	data->pos = NULL;
	return (ft_lstnew(&data));
}

int main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (NULL);
	data->head = &init_head();
	ft_printf("%s\n", data->text);
	free(data->text);
}
