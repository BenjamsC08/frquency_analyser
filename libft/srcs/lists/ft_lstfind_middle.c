/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:44:02 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:44:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_middle(t_list **head)
{
	t_list	*curr0;
	t_list	*curr1;

	if (!head || !*head)
		return (NULL);
	curr0 = *head;
	curr1 = *head;
	while (curr1 && curr1->next)
	{
		curr0 = curr0->next;
		curr1 = curr1->next->next;
	}
	return (curr0);
}

t_dlist	*ft_dlstfind_middle(t_dlist **head)
{
	t_dlist	*curr0;
	t_dlist	*curr1;

	if (!head || !*head)
		return (NULL);
	curr0 = *head;
	curr1 = *head;
	while (curr1 && curr1->next)
	{
		curr0 = curr0->next;
		curr1 = curr1->next->next;
	}
	return (curr0);
}
