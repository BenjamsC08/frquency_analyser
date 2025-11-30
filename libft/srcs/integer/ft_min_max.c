/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 03:38:40 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/23 03:48:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

int	ft_max(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	return (nb1);
}

int	*ft_mintab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				out;
	int				temp;

	if (!size || !tab)
		return (NULL);
	i = -1;
	temp = INT_MAX;
	out = 0;
	while (++i < size)
	{
		if (tab[i] < temp)
		{
			temp = tab[i];
			out = i;
		}
	}
	return (&tab[out]);
}

int	*ft_maxtab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				out;
	int				temp;

	if (!size || !tab)
		return (NULL);
	out = 0;
	i = -1;
	temp = INT_MIN;
	while (++i < size)
	{
		if (tab[i] > temp)
		{
			temp = tab[i];
			out = i;
		}
	}
	return (&tab[out]);
}
