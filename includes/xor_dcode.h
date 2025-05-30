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

/*typedef struct s_list*/
/*{*/
/*	void				*content;*/
/*	struct s_list		*next;*/
/*}						t_list;*/

typedef struct s_data
{
	char			*trinome;
	int				count;
	int				*pos;
	pthread_mutex_t	*m_node;
} t_data;

typedef struct s_reader
{
	t_long	length;
	char	*sample;
	t_list	**h_list;
} t_reader;

char	*remove_whitespace(char *str);
char	*reset_hex(char *str);
char	*hex_format(char *str, int type);

#endif
