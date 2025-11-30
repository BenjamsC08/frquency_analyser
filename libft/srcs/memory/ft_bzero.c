/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:57:27 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 20:57:34 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *addr, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)addr;
	i = -1;
	while (++i < n)
		ptr[i] = 0;
	return ;
}

/*
*
*
*takes an address and sizes, sets all address bytes to 0
*
*
*/
