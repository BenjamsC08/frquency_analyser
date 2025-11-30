/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:37:04 by moa               #+#    #+#             */
/*   Updated: 2025/02/24 00:07:12 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = 0;
	while (++i < 8)
	{
		tmp <<= 1;
		tmp |= (octet & 1);
		octet >>= 1;
	}
	return (tmp);
}

unsigned int	ft_reverse_octets(unsigned int octets)
{
	unsigned int	result;
	unsigned char	current;
	unsigned char	reversed;
	int				i;

	result = 0;
	i = -1;
	while (++i < 4)
	{
		current = (octets >> (8 * i)) & 0xFF;
		reversed = ft_reverse_bits(current);
		result |= (unsigned int)reversed << (8 * (3 - i));
	}
	return (result);
}
