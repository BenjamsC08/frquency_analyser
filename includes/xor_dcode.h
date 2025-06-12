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

#define CHAR_MIN_BY_THREADS 1024


/*typedef struct s_list*/
/*{*/
/*	void				*content;*/
/*	struct s_list		*next;*/
/*}						t_list;*/

typedef struct s_data
{
	t_uint		max_threads;
	t_ulong		char_by_thread;
	t_uint		nb_threads;
	t_list		**head;
}				t_data;

typedef struct s_data_node
{
	char			*trinome;
	int				count;
	int				*pos;
	pthread_mutex_t	*mtx_node;
} t_data_node;

typedef struct s_reader
{
	t_ulong	length;
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


#endif
