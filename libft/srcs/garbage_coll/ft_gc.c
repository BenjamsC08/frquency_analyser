/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 06:40:03 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:40:16 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc	*init_gc(void)
{
	t_gc	*head;
	void	*ptr;

	ptr = malloc(1);
	head = ft_dlstnew(ptr);
	if (!head)
		return (free(ptr), NULL);
	return (head);
}

void	*ft_gcalloc(t_gc **head, t_uint size)
{
	void		*ptr;
	t_gc		*node;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	node = ft_dlstnew(ptr);
	if (!node)
		return (free(ptr), NULL);
	ft_dlstadd_back(head, node);
	return (ptr);
}

void	*ft_gc_addnode(t_dlist **head, void *ptr)
{
	t_gc		*node;

	if (!ptr)
		return (NULL);
	node = ft_dlstnew(ptr);
	if (!node)
		return (free(ptr), NULL);
	ft_dlstadd_back(head, node);
	return (ptr);
}

void	ft_clear_gc(t_gc **head)
{
	ft_dlstclear(head, &free);
}

char	**ft_add_strs_gc(t_gc **head, char **strs)
{
	char	**ptr_strs;

	if (!strs)
		return (NULL);
	ptr_strs = strs;
	while (*strs)
	{
		ft_gc_addnode(head, *strs);
		strs++;
	}
	if (!ft_gc_addnode(head, ptr_strs))
		return (NULL);
	return (ptr_strs);
}

// Example utilisation
// int main()
// {
//     t_gc *head_gc;
//     char *str;
//     char *str1;
//     int *int_ptr;
//     head_gc = init_gc();
//     str = ft_gcalloc(&head_gc, sizeof(char *));
//     if (!str)
//         return (ft_clear_gc(&head_gc), 1);
//     str = "blaoblao";
// 	str1 = ft_gc_addnode(&head_gc, ft_strdup("lololololo"));
//     if (!str1)
//         return (ft_clear_gc(&head_gc), 1);
//     int_ptr = ft_gc_addnode(&head_gc, malloc(sizeof(int)));
//     if (!int_ptr)*/
//         return (ft_clear_gc(&head_gc), 1);
//     *int_ptr = 42;
//     ft_clear_gc(&head_gc);
//     return (0);
// }
