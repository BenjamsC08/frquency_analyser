#ifndef XOR_DECODE_H
# define XOR_DECODE_H

#include "xor_def.h"

char	*remove_whitespace(char *str);
char	*reset_hex(char *str);
char	*ft_str_insert(char *str, char *to_insert, int step);
char	*hex_format(char *str, int type);
//	multi-threading
// char	**split_for_threads(t_data *data);
int		create_threads(t_data *data);
//	data_node_utils.c
int		add_data_node(t_list **head, char *str, int pos);
int		update_data_node(t_data_node *data, int pos);
void    *extract_data_node(void *ptr_data, char type);
void    free_data_node(void *data);
//	list_utils.c
void	print_list(t_list **head);
void	destroy_list(t_list **head);

#endif
