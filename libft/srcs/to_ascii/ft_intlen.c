/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:27:01 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:33:32 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(unsigned int nb, char type)
{
	int	i;

	i = 0;
	if (type != 'u' && nb > 2147483647)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	if (i == 0)
		++i;
	return (i);
}

int	ft_lintlen(long unsigned int nb, char type)
{
	int	i;

	i = 0;
	if (type != 'u' && nb > LONG_MAX)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	if (i == 0)
		++i;
	return (i);
}
