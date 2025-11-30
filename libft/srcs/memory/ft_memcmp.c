/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:32:25 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:33:18 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *addr1, const void *addr2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	unsigned int		i;

	ptr1 = (const unsigned char *)addr1;
	ptr2 = (const unsigned char *)addr2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
