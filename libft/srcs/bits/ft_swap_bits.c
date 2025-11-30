/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:36:15 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 05:42:53 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_swap_bits(unsigned char octet)
{
	unsigned char	al;
	unsigned char	ah;

	al = octet >> 4;
	ah = octet << 4;
	return (ah + al);
}

unsigned int	ft_swap_octets(unsigned int octets)
{
	unsigned int	result;
	unsigned char	current;
	int				i;

	result = 0;
	i = -1;
	while (++i < 4)
	{
		current = (octets >> (8 * i)) & 0xFF;
		result |= (unsigned int)current << (8 * (3 - i));
	}
	return (result);
}
