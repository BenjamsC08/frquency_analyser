/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:05:00 by benjamsc          #+#    #+#             */
/*   Updated: 2025/04/15 08:05:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut(char from, char *str, int l)
{
	char	*d;
	int		i;

	i = 0;
	if (l > (int)ft_strlen(str))
		return (free(str), malloc(0));
	d = ft_calloc(sizeof(char), (ft_strlen(str) - l) + 1);
	if (!d)
		return (NULL);
	if (from == START)
	{
		while (str[l])
			d[i++] = str[l++];
	}
	else if (from == END)
	{
		l = ft_strlen(str) - l - 1;
		while (l >= 0)
			d[i++] = str[l--];
	}
	return (d);
}
/*
 *
 * take END OR START macro and return str l-sized from the macro choosed
 *
 */
