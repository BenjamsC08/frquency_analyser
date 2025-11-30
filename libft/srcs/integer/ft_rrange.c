/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:50:26 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 07:52:53 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	len;

	if (end >= start)
		len = end - start + 1;
	else
		len = start - end + 1;
	tab = (int *)ft_calloc(sizeof(int), len);
	if (!tab)
		return (NULL);
	if (end >= start)
	{
		while (len--)
		{
			tab[len] = start++;
		}
	}
	else
	{
		while (len--)
		{
			tab[len] = start--;
		}
	}
	return (tab);
}
