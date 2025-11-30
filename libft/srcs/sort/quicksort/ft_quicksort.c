/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:47:42 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:47:52 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pivoting_all(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = low - 1;
	j = low - 1;
	while (++j <= high)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
	}
	ft_swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

static void	sort(int *tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = pivoting_all(tab, low, high);
		sort(tab, low, pivot - 1);
		sort(tab, pivot + 1, high);
	}
}

void	ft_quicksort(int *tab, int length)
{
	sort(tab, 0, length - 1);
}
