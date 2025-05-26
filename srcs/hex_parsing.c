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

int	type_analyser(char *str)
{
	int	type = 0;

	printf("%s\n",str);
	if (str[0] == 'x' || str[0] == 'X')
		type = 1;
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		type = 2;
	else
		type = 3;
	return (type);
}
// 1 \x without space or new line
// 2 \x with space bettween octet
// 3 \x with newline bettween octet
// 4 0x without space or new line
// 5 0x with space bettween octet
// 6 0x with newline bettween octet
// 7 nothing to do is what we're aiming for
// 8 octet in hex but separate with space
// 9 octet in hex but separate with newline
/*char	*from_hex(char *str)*/
/*{*/
/**/
/*}*/
int main(int argc, char **argv)
{
	char  *input_user;
	if (argc == 2)
	{
		input_user = remove_whitespace(argv[1]);
		printf("%d\n", type_analyser(input_user));
		free(input_user);
	}
}
