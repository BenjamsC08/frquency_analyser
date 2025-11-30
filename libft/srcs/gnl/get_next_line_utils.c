/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:00:14 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/12 20:43:43 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	char	*out;
	char	*s_1;
	char	*s_2;

	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (! new)
		return (0);
	out = new;
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		*new++ = *s_1++;
	while (*s_2)
		*new++ = *s_2++;
	*new = 0;
	free(s1);
	return (out);
}

int	found_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}
