/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:06:20 by benjamsc          #+#    #+#             */
/*   Updated: 2025/04/15 08:05:19 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsplit(char **strs, char c)
{
	int		i;
	char	*s;
	char	*sep;

	if (!*strs || !strs)
		return (NULL);
	sep = ft_calloc(sizeof(char), 2);
	if (!sep)
		return (NULL);
	sep[0] = (char)c;
	s = ft_strdup(strs[0]);
	if (!s)
		return (free(sep), NULL);
	i = 1;
	while (strs[i])
	{
		s = ft_strfjoin(s, sep);
		if (!s)
			return (free(sep), NULL);
		s = ft_strfjoin(s, strs[i++]);
		if (!s)
			return (free(sep), NULL);
	}
	return (free(sep), s);
}

static char	*join_help(char *s, char *sep, char *end)
{
	s = ft_strfjoin(s, sep);
	if (!s)
		return (NULL);
	s = ft_strfjoin(s, end);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_unsplit_skip(char **strs, const char c, int k)
{
	static int	i = 0;
	char		*s;
	char		*sep;

	if (!*strs || !strs)
		return (NULL);
	sep = ft_calloc(sizeof(char), 2);
	if (!sep)
		return (NULL);
	sep[0] = (char) c;
	if (k == 0)
		i++;
	s = ft_strdup(strs[i]);
	if (!s)
		return (free(sep), NULL);
	while (strs[++i])
	{
		if (k == i)
			continue ;
		s = join_help(s, sep, strs[i]);
		if (!s)
			return (free(sep), NULL);
	}
	return (free(sep), s);
}
