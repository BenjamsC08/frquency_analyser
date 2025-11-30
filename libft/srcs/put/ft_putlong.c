/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:47:02 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:47:22 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlong(long int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_putchar('0'));
	s1 = ft_ltoa(nb);
	if (!s1)
		return (0);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_putlong_fd(int fd, long int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_putchar_fd(fd, '0'));
	s1 = ft_ltoa(nb);
	if (!s1)
		return (0);
	s = s1;
	while (*s1)
		write(fd, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}
