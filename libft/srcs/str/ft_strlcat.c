/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:42:57 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/13 18:42:20 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	unsigned int	len_s;
	unsigned int	len_d;
	unsigned int	i;
	char			*s;
	char			*d;

	i = -1;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (siz <= len_d)
		return (len_s + siz);
	s = (char *)src;
	d = dst + len_d;
	while (*s && ++i < siz - len_d - 1)
		*(d++) = *(s++);
	*d = '\0';
	return ((size_t)(len_d + len_s));
}
/*
int main()
{
	#include <stdio.h>
	const char *s = "4200";
	char dest[30] = "i love ";
	printf("%d \n",ft_strlcat(dest, (const char*)s, 9));
	printf("%s\n",dest);
}*/
