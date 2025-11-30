/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:47:06 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:47:25 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long nbr)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_putstr("(nil)"));
	s1 = ft_xtoa(nbr, 'x');
	s = s1;
	write(1, "0x", 2);
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len + 2);
}

int	ft_putptr_fd(int fd, unsigned long nbr)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_putstr_fd(fd, "(nil)"));
	s1 = ft_xtoa(nbr, 'x');
	s = s1;
	write(1, "0x", 2);
	while (*s1)
		write(fd, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len + 2);
}
