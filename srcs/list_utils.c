#include "xor_dcode.h"

void	destroy_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	if (!head || !*head)
		return ;
	current = *head;
	next = NULL;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, &free_data_node);
		current = next;
	}
	*head = NULL;
}

void	print_list(t_list **head)
{
	t_list	*current;
	int		count;
	int		*pos;
	int		i;

	current = *head;
	while (current)
	{
		i = -1;
		count = (*(int *)extract_data_node(current->content, COUNT));
		pos = (int *)extract_data_node(current->content, POS);
		ft_fprintf(1, "trigram :'%s', count :'%d', ", (char *)extract_data_node(current->content, TRIGRAM),
			 count);
		while (++i < count)
			ft_fprintf(1, "pos[%d]=%d, ", i, pos[i]);
		ft_fprintf(1,"\n");
		current = current->next;
	}
}
