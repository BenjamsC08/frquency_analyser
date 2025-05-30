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

int main(int argc, char **argv)
{
	char	*str;

	str = get_hex(argc, argv);
	if (!str)
		return (1);
	ft_printf("%s\n", str);
	free(str);
}
