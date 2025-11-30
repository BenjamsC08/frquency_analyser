/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:25 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:39:25 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_only_whitespace(char *str)
{
	char	*src;

	src = str;
	while (*src)
	{
		if (!ft_iswhitespace(*src))
			return (0);
	}
	return (1);
}
