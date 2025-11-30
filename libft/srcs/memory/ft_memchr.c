/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:40:44 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:38:47 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *addr, int c, size_t n)
{
	char			*mb;
	char			ch;
	unsigned int	i;

	ch = (char)c;
	mb = (char *)addr - 1;
	i = -1;
	while (++i < n)
	{
		if (*(++mb) == ch)
			return (mb);
	}
	return (0);
}
