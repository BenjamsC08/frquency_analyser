/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:33:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:34:15 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	if (!dest || !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	i = -1;
	while (++i < n)
		*(d++) = *(s++);
	return (dest);
}
