#ifndef XOR_DECODE_H
# define XOR_DECODE_H

# include "libft.h"
# include <pthread.h>

# define ONE_LINE 0
# define ZEROX 1
# define BSX 2			// backslashx //x
# define SPACE 3
# define COLUMN 4
# define SEMI_COL 5
# define COMMA 6

#define TRINOME 'T'
#define POS 'P'
#define MTX 'M'
#define COUNT 'C'

#define CHAR_MIN_BY_THREADS 1024

typedef pthread_mutex_t t_mtx;

/*typedef struct s_list*/
/*{*/
/*	void				*content;*/
/*	struct s_list		*next;*/
/*}						t_list;*/

typedef struct s_data
{
	char		*text;
	t_uint		max_threads;
	t_ulong		char_by_thread;
	t_uint		nb_threads;
	pthread_t	*threads
	t_list		**head;
}				t_data;

typedef struct s_data_node
{
	char	*trinome;
	int		count;
	int		*pos;
	t_mtx	*mtx_node;
} t_data_node;

typedef struct s_reader
{
	char	*sample;
	t_ulong	length;
	t_list	**h_list;
} t_reader;

// format HEX
char	*remove_whitespace(char *str);
char	*reset_hex(char *str);
char	*hex_format(char *str, int type);
// multi-threading
char	**split_for_threads(char *str, t_data *data);
//data_node
void    create_data_node(t_list **head, char *str, int pos);
void	update_data_node(t_data_node *data, int pos);
void    *extract_data_node(void *ptr_data, char type);
void    free_data_node(t_data_node *data);

#endif
