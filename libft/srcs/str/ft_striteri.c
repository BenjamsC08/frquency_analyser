/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:42:07 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:42:44 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		f(i, (s + i));
}
/*
void  ft_4fun(unsigned int n, char *c)
{
  *c += n%26;
}
int main()
{
  char str[] = "abcdefgh";
  ft_striteri(str, &ft_4fun);
  #include <stdio.h>
  printf("%s\n",str);
}*/
