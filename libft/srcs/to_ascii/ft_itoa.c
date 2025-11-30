/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:22 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/21 14:59:13 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				len_nb;
	char			*str_nb;
	unsigned int	nbr;

	nbr = n;
	len_nb = ft_intlen(nbr, 'i');
	str_nb = (char *)ft_calloc((len_nb + 1), sizeof(char));
	if (! str_nb)
		return (0);
	if (n == 0)
		str_nb[0] = '0';
	else
	{
		if (n < 0)
			nbr = -nbr;
		while ((len_nb--) > 0)
		{
			str_nb[len_nb] = nbr % 10 + '0';
			nbr /= 10;
		}
		if (n < 0)
			*str_nb = '-';
	}
	return (str_nb);
}
/*
int	main(int argc, char **argv)
{
	#include <stdio.h>
	(void)argc;
	printf("ft_itoa : %s\n", ft_itoa(atoi(argv[1])));
}*/
