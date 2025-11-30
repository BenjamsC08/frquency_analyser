/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_substring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:38 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:39:41 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*end_copy(char *str, char length, char **ptr_d, char **dest)
{
	char	*d;

	d = *ptr_d;
	str += length;
	while (*str)
		*(d++) = *(str++);
	return (*dest);
}

char	*ft_remove_substring(char *str, const char *sub)
{
	char	*dest;
	char	*cr;
	char	*s;
	char	*d;

	cr = (char *)sub;
	s = ft_strstr(str, cr);
	if (ft_strlen(cr) > ft_strlen(str) || !s)
		return (NULL);
	dest = ft_calloc(sizeof(char), ft_strlen(str));
	if (!dest)
		return (NULL);
	d = dest;
	while (*str)
	{
		while (str != s)
			*(d++) = *(str++);
		s = ft_strstr((s + ft_strlen(cr)), cr);
		if (!s)
			return (end_copy(str, ft_strlen(cr), &d, &dest));
		str += ft_strlen(cr);
	}
	return (dest);
}
