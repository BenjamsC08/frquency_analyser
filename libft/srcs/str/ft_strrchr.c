/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:48:09 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:49:42 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*str;
	char		*s_end;
	char		cr;

	cr = (unsigned char) c;
	if (cr == 0)
		return ((char *)(s + ft_strlen(s)));
	str = (char *)s - 1;
	s_end = 0;
	while (*(++str))
	{
		if (*str == cr)
			s_end = str;
	}
	return (s_end);
}
/*
int main()
{
  #include <stdio.h>
  #include <string.h>
	char *str = "teste";
  //printf("%d\n",("t"+256));
  printf("%p\n%p",&str, ft_strrchr(str,'e'));
}*/
