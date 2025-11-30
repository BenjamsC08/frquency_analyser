/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:05:35 by benjamsc          #+#    #+#             */
/*   Updated: 2025/04/15 08:05:37 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_add_char(char *str, char c)
{
	char	*new;
	char	*out;
	char	*s_1;

	if (!str)
		return (NULL);
	if (!c)
		return (str);
	new = (char *)ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!new)
		return (0);
	out = new;
	s_1 = (char *)str;
	while (*s_1)
		*new ++ = *s_1++;
	*new = c;
	free(str);
	return (out);
}
