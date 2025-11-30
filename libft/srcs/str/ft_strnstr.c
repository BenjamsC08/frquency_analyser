/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:47:24 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:47:58 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char		*s;
	const char		*save;
	const char		*tf;
	unsigned int	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		s = big + i;
		tf = little;
		save = s;
		while (*s && *tf && (*s == *tf) && (i < len))
		{
			s++;
			tf++;
			i++;
		}
		if (!*tf)
			return ((char *)save);
		i = save - big + 1;
	}
	return (0);
}
/*
int main(int argc, char **argv)
{
	#include <stdio.h>
	(void)argc;
	char *haystack = argv[1];
	char *needle = argv[2];
	char *result;
	printf("we look for %p in %s\n", needle, haystack);
	result = ft_strnstr((const char *)haystack,
	(const char *)needle, atoi(argv[3]));
	printf("right there : %s\n", result);
}*/
