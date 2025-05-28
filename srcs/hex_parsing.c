#include <stdio.h>
#include "libft.h"

int	ft_ishex(char c)
{
	char	charset_l[] = "0123456789abcdef";
	char	charset_u[] = "0123456789ABCDEF";
	int		i = -1;

	while (charset_l[++i])
	{
		if (c == charset_l[i])
			return (1);
	}
	i = -1;
	while (charset_u[++i])
	{
		if (c == charset_l[i])
			return (1);
	}
	return (0);
}

char *remove_whitespace(char *str)
{
	char	*output;
	char	*out;

	output = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!output)
		return (NULL);
	out = output;
	while (*str)
	{
		if (ft_iswhitespace(*str))
		{
			str++;
			continue ;
		}
		*(out++) = *(str++);
	}
	return (output);
}

char	*reformat_hex(char *str)
{
	if (str[0] == 'x')
		return (ft_remove_charset(str, "x"));
	if (str[0] == 'X')
		return (ft_remove_charset(str, "X"));
	if (str[0] == '0' && str[1] == 'x')
		return (ft_remove_substring(str, "0x"));
	else if (str[0] == '0' && str[1] == 'X')
		return (ft_remove_substring(str, "0X"));
	if (str[2] == ':' || str[2] == ';' || str[2] == ',')
		return (ft_remove_charset(str, ":;,"));
	else
		return (ft_strdup(str));
	return (NULL);
}

char	*from_hex(char *str)
{
	char  *input_user;

	input_user = remove_whitespace(str);
	str = reformat_hex(input_user);
	free(input_user);
	return (str);
}

int main(int argc, char **argv)
{
	char  *input_clean;
	if (argc == 2)
	{
		input_clean = from_hex(argv[1]);
		printf("%s\n",input_clean);
		free(input_clean);
	}
}
