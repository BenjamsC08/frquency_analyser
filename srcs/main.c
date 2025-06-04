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

t_data	*init_data()
{
	t_data data;

	data->max_threads = 6;
	data->char_by_thread = CHAR_MIN_BY_THREADS;
	data->nb_threads = 1;
}

int main(int argc, char **argv)
{
	char	*str;

	str = get_hex(argc, argv);
	if (!str)
		return (1);
	ft_printf("%s\n", str);
	free(str);
}
