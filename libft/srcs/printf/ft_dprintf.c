/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:02:03 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/12 21:05:04 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_format(int fd, va_list list, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar_fd(fd, va_arg(list, int));
	if (type == 's')
		len += ft_putstr_fd(fd, va_arg(list, char *));
	if (type == 'p')
		len += ft_putptr_fd(fd, va_arg(list, unsigned long));
	if (type == 'd' || type == 'i')
		len += ft_putnbr_fd(fd, va_arg(list, int));
	if (type == 'u')
		len += ft_putuint_fd(fd, va_arg(list, unsigned int));
	if (type == 'x' || type == 'X')
		len += ft_puthex_fd(fd, va_arg(list, unsigned int), type);
	if (type == 'l')
		len += ft_putlong_fd(fd, va_arg(list, long int));
	if (type == '%')
		len += ft_putchar_fd(fd, '%');
	return (len);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	list;
	int		length;
	char	*s;

	if (!str || fd < 0 || fd > 1024)
		return (-1);
	s = (char *)str - 1;
	length = 0;
	va_start(list, str);
	while (*(++s))
	{
		if (*s == '%')
			length += parse_format(fd, list, *(++s));
		else
			length += ft_putchar_fd(fd, *s);
	}
	va_end(list);
	return (length);
}
