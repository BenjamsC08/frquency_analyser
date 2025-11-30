/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 04:17:14 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/29 04:17:51 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishex(char c)
{
	static char	charset_l[] = "0123456789abcdefxX";
	static char	charset_u[] = "0123456789ABCDEFxX";
	int			i;

	i = -1;
	while (charset_l[++i])
	{
		if (c == charset_l[i])
			return (1);
	}
	i = -1;
	while (charset_u[++i])
	{
		if (c == charset_l[i])
			return (1);
	}
	return (0);
}
