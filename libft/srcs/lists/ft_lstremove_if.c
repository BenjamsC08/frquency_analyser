/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:44:38 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:46:26 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **head, void *ref, int (*cmp)(void *, void *, size_t), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*curr;

	while (*head && !cmp((*head)->content, ref, sizeof(void *)))
	{
		tmp = *head;
		*head = (*head)->next;
		ft_lstdelone(tmp, del); 
	}
	curr = *head;
	while (curr && curr->next)
	{
		if (!cmp(curr->next->content, ref, sizeof(void *)))
		{
			tmp = curr->next;
			curr->next = tmp->next;
			del(tmp->content);
			free(tmp);
		}
		else
		{
			curr = curr->next;
		}
	}
}


// void	ft_dlstremove_if(t_dlist **head, void *ref, int (*cmp)())
// {
// 	t_dlist	*tmp;
// 	t_dlist	*i;
//
// 	while (*head && !cmp((*head)->content, ref, sizeof(void *)))
// 	{
// 		tmp = *head;
// 		*head = (*head)->next;
// 		if (*head)
// 			(*head)->prev = NULL;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// 	i = *head;
// 	while (i && i->next)
// 	{
// 		if (!cmp(i->next->content, ref, sizeof(void *)))
// 		{
// 			tmp = i->next;
// 			i->next = tmp->next;
// 			if (tmp->next)
// 				tmp->next->prev = i;
// 			free(tmp->content);
// 			free(tmp);
// 		}
// 		else
// 			i = i->next;
// 	}
// }
