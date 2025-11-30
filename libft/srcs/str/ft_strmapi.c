/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:45:13 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:46:08 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*so;
	char			*s_out;

	so = (char *)ft_calloc(sizeof(char), (ft_strlen((char *)s) + 1));
	if (! so)
		return (NULL);
	s_out = so;
	i = -1;
	while (s[(++i)])
		*(so++) = f(i, s[i]);
	*so = '\0';
	return (s_out);
}
/*
char  ft_4fun(unsigned int n, char c)
{
  return((c+(n%26)));
}
int main()
{
  char const *str = "abcdefgh";
  char *end = ft_strmapi(str, &ft_4fun);
  #include <stdio.h>
  printf("%s\n",end);
  free(end);

}*/
