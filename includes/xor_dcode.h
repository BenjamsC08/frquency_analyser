#ifndef XOR_DECODE_H
# define XOR_DECODE_H

#include "xor_def.h"

//	hex_parsing.c
char		*remove_whitespace(char *str);
char		*reset_hex(char *str);
char		*ft_str_insert(char *str, char *to_insert, int step);
char		*hex_format(char *str, int type);
//	inits.c
t_list		*init_head(char *tri);
t_reader	*init_data_threads(t_data *data, char *str, int i, t_mtx **mutex);
//	multi-threading
int			create_threads(t_data *data);
//	data_node_utils.c
int			add_data_node(t_list *last, char *str, int pos);
int			update_data_node(t_data_node *data, int pos);
void		*extract_data_node(void *ptr_data, char type);
void		free_data_node(void *data);
//	list_utils.c
char		**split_for_threads(t_data *data);
void		print_list(t_list **head);
void		destroy_list(t_list **head);

#endif
