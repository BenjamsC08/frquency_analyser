/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:30:47 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/04 08:30:50 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long int n)
{
	int			len_nb;
	char		*str_nb;
	long int	nbr;

	nbr = n;
	len_nb = ft_lintlen(nbr, 'i');
	str_nb = (char *)ft_calloc((len_nb + 1), sizeof(char));
	if (!str_nb)
		return (0);
	if (n == 0)
		str_nb[0] = '0';
	else
	{
		if (n < 0)
			nbr = -nbr;
		while ((len_nb--) > 0)
		{
			str_nb[len_nb] = nbr % 10 + '0';
			nbr /= 10;
		}
		if (n < 0)
			*str_nb = '-';
	}
	return (str_nb);
}

char	*ft_ultoa(unsigned long int n)
{
	int					len_nb;
	char				*str_nb;
	unsigned long int	nbr;

	nbr = n;
	len_nb = ft_lintlen(nbr, 'u');
	str_nb = (char *)ft_calloc((len_nb + 1), sizeof(char));
	if (!str_nb)
		return (0);
	if (n == 0)
		str_nb[0] = '0';
	else
	{
		while ((len_nb--) > 0)
		{
			str_nb[len_nb] = nbr % 10 + '0';
			nbr /= 10;
		}
	}
	return (str_nb);
}
