/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:37:21 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:37:55 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_format(va_list list, char type)
{
	int		len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(list, int));
	if (type == 's')
		len += ft_putstr(va_arg(list, char *));
	if (type == 'p')
		len += ft_putptr(va_arg(list, unsigned long));
	if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(list, int));
	if (type == 'u')
		len += ft_putuint(va_arg(list, unsigned int));
	if (type == 'x' || type == 'X')
		len += ft_puthex(va_arg(list, unsigned int), type);
	if (type == 'l')
		len += ft_putlong(va_arg(list, long int));
	if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	int			length;
	char		*s;

	if (!str)
		return (-1);
	s = (char *)str - 1;
	length = 0;
	va_start(list, str);
	while (*(++s))
	{
		if (*s == '%')
			length += parse_format(list, *(++s));
		else
			length += ft_putchar(*s);
	}
	va_end(list);
	return (length);
}
