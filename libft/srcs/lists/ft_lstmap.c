/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:27:49 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:27:53 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*act;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	act = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		act->next = tmp;
		act = tmp;
		lst = lst->next;
	}
	return (new);
}

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*act;
	t_dlist	*tmp;

	if (!lst || !f)
		return (0);
	new = ft_dlstnew(f(lst->content));
	if (!new)
		return (0);
	act = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_dlstnew(f(lst->content));
		if (!tmp)
		{
			ft_dlstclear(&new, del);
			return (0);
		}
		act->next = tmp;
		act = tmp;
		lst = lst->next;
	}
	return (new);
}
