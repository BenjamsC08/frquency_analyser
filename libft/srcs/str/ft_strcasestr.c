/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:27:40 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 07:07:42 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_tf(char *s, char *tf)
{
	char	*to_find;
	int		i;

	to_find = tf;
	i = 0;
	while (*(to_find++))
	{
		i++;
		if (!*to_find)
			return (1);
		if (s[i] != *to_find)
			return (0);
	}
	return (-1);
}

static void	ft_alloc_and_lower(char *str, char *to_find, char **s, char **tf)
{
	int		i;

	*s = ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	*tf = ft_calloc(sizeof(char), (ft_strlen(to_find) + 1));
	if (!*s || !*tf)
		return ;
	if (!*tf)
		return (free(*tf));
	i = -1;
	while (str[++i])
		(*s)[i] = ft_tolower(str[i]);
	i = -1;
	while (to_find[++i])
		(*tf)[i] = ft_tolower(to_find[i]);
	return ;
}

char	*ft_strcasestr(char *str, char *to_find)
{
	char	*s;
	char	*tf;
	int		i;

	if (!to_find)
		return (str);
	ft_alloc_and_lower(str, to_find, &s, &tf);
	if (!s || !tf)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == tf[0])
		{
			if (ft_check_tf(&s[i], tf))
				return (free(s), free(tf), &str[i]);
			else
				i = 0;
		}
	}
	free(s);
	free(tf);
	return (NULL);
}

/*
 *
 * Prend 2 chaine de char en entree
 * retourne 1 si to_find est dans str peut importe si c'est maj ou non
 *
 * Takes 2 strings as input
 * returns 1 if to_find is in str, regardless of whether it's uppercase or not
 */
