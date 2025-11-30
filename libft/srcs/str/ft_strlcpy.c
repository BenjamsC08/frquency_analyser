/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:43:52 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:45:02 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*s;
	char			*d;

	i = -1;
	len_s = ft_strlen((char *)src);
	if (siz == 0)
		return (len_s);
	s = (char *)src;
	d = dst;
	while (*s && ++i < siz - 1)
		*(d++) = *(s++);
	*d = '\0';
	return (len_s);
}
