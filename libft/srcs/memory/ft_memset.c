/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:41:06 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:36:19 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *addr, int c, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)addr;
	i = -1;
	while (++i < n)
		ptr[i] = (char)c;
	return (addr);
}
/*
#include <string.h>
#include <stdio.h>
int main() {

  int array [] = { 54, 85, 20, 63, 21 };
  int array1 [] = { 54, 85, 20, 63, 21 };
  size_t size = sizeof( int ) * 5;
  int length;

  for( length=0; length<5; length++) {
    printf( "%d ", array[ length ] );
  }
  printf( "\n" );
  for( length=0; length<5; length++) {
    printf( "%d ", array1[ length ] );
  }
  printf( "\n" );

  ft_memset( array, -2147483648, size );
  memset(array1, -2147483648, size);

  for( length=0; length<5; length++) {
    printf( "%d ", array[ length ] );
  }
  printf( "\n" );
  for( length=0; length<5; length++) {
    printf( "%d ", array1[ length ] );
  }
  printf( "\n" );
    
    return 0;
}
*/
