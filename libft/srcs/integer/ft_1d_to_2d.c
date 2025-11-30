/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_to_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:41:00 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:43:32 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_1d_to_2d_int(t_gc **gc, const int *tab, int rows, int cols)
{
	int	**out;
	int	i;
	int	j;

	out = ft_gcalloc(gc, sizeof(int *) * rows);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		out[i] = ft_gcalloc(gc, sizeof(int) * cols);
		if (!out[i])
			return (NULL);
		j = -1;
		while (++j < cols)
			out[i][j] = tab[i * cols + j];
	}
	return (out);
}
