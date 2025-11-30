/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:52 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:40:02 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	if (!*strs)
		return (free(strs));
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

void	ft_free_instrs(char **tab)
{
	int	i;

	if (!tab || !(*tab))
		return ;
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
}
