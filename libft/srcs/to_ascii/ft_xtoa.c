/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:34:25 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:34:37 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xtoa(unsigned long nbr, char type)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	if (type == MAJ_HEX)
		base = "0123456789ABCDEF";
	len = ft_xlen(nbr);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	*(str + len) = 0;
	while ((len--) > 0)
	{
		str[len] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}
