/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:51:37 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/13 16:54:48 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs)
{
	char	**strs_c;
	char	**strs_c_ptr;
	int		nb_lines;

	if (!strs || !*strs)
		return (NULL);
	nb_lines = ft_strslen(strs);
	strs_c = (char **)ft_calloc((nb_lines + 1), sizeof(char *));
	if (!strs_c)
		return (NULL);
	strs_c_ptr = strs_c;
	while (*strs)
		*(strs_c++) = ft_strdup(*(strs++));
	*strs_c = NULL;
	return (strs_c_ptr);
}
