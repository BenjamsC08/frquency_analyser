/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:27 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:39:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_remove_charset(char *str, const char *charset)
{
	char	*dest;
	char	*d;

	dest = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	d = dest;
	while (*str)
	{
		if (!ft_ischarset(*str, charset))
			*(d++) = *str;
		str++;
	}
	return (dest);
}
