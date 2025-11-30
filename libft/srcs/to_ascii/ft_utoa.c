/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:31:03 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:32:25 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	nbr;

	nbr = n;
	len = ft_intlen(nbr, 'u');
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (! str)
		return (0);
	*(str + len) = 0;
	while ((len--) > 0)
	{
		str[len] = (nbr % 10 + '0');
		nbr /= 10;
	}
	return (str);
}
