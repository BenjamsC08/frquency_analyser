
int	ft_ishex_val(char c)
{
	char	charset_l = "0123456789abcdef";
	char	charset_u = "0123456789ABCDEF";
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

int	type_analyser(char *str)
{
	int	type = 0;

	if (str[0] && str[1] == 'x' && str[4])
	{
		if (str[0] == '\\')
			type = 1;
		else if (str[0] == '0')
			type = 4;
		if (str[4] == ' ')
			type += 1;
		else if (str[4] == '\n')
			type += 2;

	}
	else if (ft_ishex_val(str[0]) && ft_ishex_val(str[1]))
	{
		type = 7;
		if (str[2] == ' ')
			type++;
		if (str[2] == '\n')
			type += 2;
	}
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
char	*from_hex(char *str)
{

}
