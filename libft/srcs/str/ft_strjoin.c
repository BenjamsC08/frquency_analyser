/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:42:49 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:40:14 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (0);
	out = new;
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		*new ++ = *s_1++;
	while (*s_2)
		*new ++ = *s_2++;
	*new = 0;
	return (out);
}

char	*ft_strfjoin(char *src, char *dest)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	new = (char *)ft_calloc((ft_strlen(src) + ft_strlen(dest) + 1),
			sizeof(char));
	if (!new)
		return (0);
	out = new;
	s_1 = (char *)src;
	s_2 = (char *)dest;
	while (*s_1)
		*new ++ = *s_1++;
	while (*s_2)
		*new ++ = *s_2++;
	*new = 0;
	free(src);
	return (out);
}
