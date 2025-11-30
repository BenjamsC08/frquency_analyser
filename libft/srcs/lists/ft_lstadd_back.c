/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:10:29 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:12:03 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (! lst || ! new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	if (! lst || ! new)
		return ;
	if (*lst)
	{
		new->prev = ft_dlstlast(*lst);
		ft_dlstlast(*lst)->next = new;
	}
	else
	{
		*lst = new;
		(*lst)->prev = NULL;
	}
}
