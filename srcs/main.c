#include "xor_dcode.h"

char  *get_hex(char **argv)
{
	char *str;
	char *s;

	str = ft_strdup(*argv);
	if (!str)
		return (NULL);
	while (*(++argv))
	{
		s = str;
		str = ft_strfjoin(str, *argv);
		if (!str)
			return (free(s), NULL);
	}
	s = reset_hex(str);
	free(str);
	return (s);
}

int main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
		str = reset_hex(*(++argv));
	else
		str = get_hex(++argv);
	if (!str)
		return (1);
	ft_printf("%s\n",str);
	free(str);
}
