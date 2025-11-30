/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:48:25 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:48:28 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, t_uint n)
{
	char	*str;
	char	*src;

	if (!s)
		return (NULL);
	str = (char *)ft_calloc((n + 1), sizeof(char));
	if (! str)
		return (0);
	src = str;
	while (*s && n > 0)
	{
		*(str++) = *(s++);
		n--;
	}
	return (src);
}
