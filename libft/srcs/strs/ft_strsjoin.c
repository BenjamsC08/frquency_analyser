/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:57 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:39:59 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsfadd(char **src, char *add)
{
	char	**new;
	char	**out;
	char	**src1;
	char	*add1;

	new = (char **)ft_calloc((ft_strslen(src) + 2), sizeof(char *));
	if (!new)
		return (free_strs(src), NULL);
	out = new;
	src1 = src;
	add1 = add;
	while (*src1)
	{
		*new = ft_strdup(*src1++);
		if (!*new)
			return (free_strs(out), free_strs(src), NULL);
		new ++;
	}
	if (add1)
		*new = ft_strdup(add1);
	if (!*new)
		return (free_strs(out), free_strs(src), NULL);
	return (free_strs(src), out);
}

char	**ft_strsfjoin(char **s1, char **s2)
{
	char	**new;

	if (!s1 || !*s1 || !s2 || !*s2)
		return (NULL);
	new = ft_strsdup(s1);
	while (*s2)
	{
		new = ft_strsfadd(new, *s2);
		s2++;
	}
	free_strs(s1);
	free_strs(s2);
	return (new);
}
