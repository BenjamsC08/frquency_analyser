/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:37:06 by moa               #+#    #+#             */
/*   Updated: 2025/02/04 06:48:31 by moa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_tf(char *s, char *tf)
{
	char	*to_find;

	to_find = tf;
	while (*(to_find++))
	{
		s++;
		if (!*to_find)
			return (1);
		if (*s != *to_find)
			return (0);
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*save_s;
	char	*s;
	char	*tf;

	if (!*to_find)
		return (str);
	s = str - 1;
	tf = to_find;
	while (*(++s))
	{
		if (*s == *tf)
		{
			save_s = s;
			if (ft_check_tf(s, tf))
				return (save_s);
			else
			{
				s = save_s;
				tf = to_find;
			}
		}
	}
	return (0);
}
