#include "xor_dcode.h"

int	ft_ischarset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_only_charset(char *str, const char *charset)
{
	while (*str)
	{
		if (!ft_ischarset(*str, (char *)charset))
			return (0);
		str++;
	}
	return (1);
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

char	*reset_hex(char *str)
{
	char  *iu;
	char  *out;
	
	iu = remove_whitespace(str);
	if (!iu)
		return (NULL);
	if (!ft_only_charset(iu, "0123456789abcdefABCDEFxX:;,"))
		return (free(iu), NULL);
	out = NULL;
	if (iu[0] == 'x')
		out = ft_remove_charset(iu, "x");
	if (iu[0] == 'X')
		out = ft_remove_charset(iu, "X");
	if (iu[0] == '0' && iu[1] == 'x')
		out = ft_remove_substring(iu, "0x");
	if (iu[0] == '0' && iu[1] == 'X')
		out = ft_remove_substring(iu, "0X");
	if (iu[2] == ':' || iu[2] == ';' || iu[2] == ',')
		out = ft_remove_charset(iu, ":;,");
	if (!out)
		return (iu);
	free(iu);
	return (out);
}
