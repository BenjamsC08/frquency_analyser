/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:54:37 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:48:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **strs)
{
	int	j;

	if (!strs || !*strs)
		return (0);
	j = 0;
	while (strs[j])
		j++;
	return (j);
}

int	ft_strs_char_count(char **strs)
{
	int	j;
	int	i;

	if (!strs || !*strs)
		return (0);
	j = 0;
	while (strs[j])
	{
		i = 0;
		while (strs[j][i])
			i++;
		j++;
	}
	return (i);
}
