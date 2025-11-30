/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:09:37 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/04 00:55:14 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_only_charset(char *str, const char *charset)
{
	while (*str)
	{
		if (!ft_ischarset(*str, (char *)charset))
			return (0);
		str++;
	}
	return (1);
}
