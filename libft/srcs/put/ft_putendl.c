/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:46:58 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:46:58 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl(char *s)
{
	int		len;

	len = ft_putstr(s);
	len += write(1, "\n", 1);
	return (len);
}

int	ft_putendl_fd(int fd, char *s)
{
	int		len;

	len = ft_putstr_fd(fd, s);
	len += write(fd, "\n", 1);
	return (len);
}
