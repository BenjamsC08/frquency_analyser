/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:55:24 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:39:03 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>



/**********************************************************************************************************************/
/**********************************************************************************************************************/
/*********************************************** Define ***************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/*
 * BOOL
 */

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#ifndef SUCCESS
	#define SUCCESS 0
#endif

#ifndef FAILED
	#define FAILED 1
#endif

/*
 * STD
 */

#ifndef STDIN
	#define STDIN 0
#endif

#ifndef STDOUT
	#define STDOUT 1
#endif

#ifndef STDERR
	#define STDERR 2
#endif
/*
 *	LIMITS
 */

#ifndef UINT_MAX
	#define UINT_MAX 4294967295
#endif

#ifndef INT_MAX
	#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
	#define INT_MIN -2147483648
#endif

#ifndef ULONG_MAX
	#define ULONG_MAX 18446744073709551615
#endif

#ifndef LONG_MAX
	#define LONG_MAX 9223372036854775807
#endif

#ifndef LONG_MIN
	#define LONG_MIN -9223372036854775808
#endif

#ifndef PATH_MAX
	#define PATH_MAX 8192
#endif

#ifndef ARG_MAX
	#define ARG_MAX 4194304
#endif

#ifndef SIZE_MAX
	#define SIZE_MAX 4294967295
#endif


/*
 *	Colors
*/ 

#ifndef RESET
	#define RESET "\033[0m"
#endif

#ifndef RED
	#define RED "\033[0;31m"
#endif

#ifndef GREEN
	#define GREEN "\033[0;32m"
#endif

#ifndef YELLOW
	#define YELLOW "\033[0;33m"
#endif

#ifndef BLUE
	#define BLUE "\033[0;34m"
#endif

#ifndef MAGENTA
	#define MAGENTA "\033[0;35m"
#endif

#ifndef CYAN
	#define CYAN "\033[0;36m"
#endif

#ifndef WHITE
	#define WHITE "\033[0;37m"
#endif

#ifndef WHITE
	#define WHITE "\033[0;91m"
#endif

#ifndef PURPLE
	#define PURPLE "\033[0;95m"
#endif

#ifndef DARK_ORANGE
	#define DARK_ORANGE "\033[0;33m"
#endif

#ifndef PINK
	#define PINK "\033[0;95m"
#endif

#ifndef TEAL
	#define TEAL "\033[0;96m"
#endif

#ifndef GRAY
	#define GRAY "\033[0;90m"
#endif

/*
 *	MISC
 */

#ifndef START
	#define START 'S'
#endif

#ifndef END
	#define END 'E'
#endif

#ifndef SIMPLE
	#define SIMPLE 's'
#endif

#ifndef DOUBLE
	#define DOUBLE 'd'
#endif

#ifndef MAJ_HEX
	#define MAJ_HEX 'X'
#endif

#ifndef MIN_HEX
	#define MIN_HEX 'x'
#endif

#ifndef PI
	#define PI 3.14159265359
#endif

/*
 *	Struct
 */

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

/*
 *	types
 */

typedef int				t_bool;
typedef unsigned char	t_byte;
typedef unsigned long	t_ulong;
typedef unsigned long	t_uintptr;
typedef unsigned int	t_uint;
typedef t_dlist			t_gc;



/**********************************************************************************************************************/
/**********************************************************************************************************************/
/****************************************** Func Declaration **********************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/*
 *			bit manips
 */
unsigned char	ft_swap_bits(unsigned char octet);
t_uint			ft_reverse_bits(t_uint octets);
void			ft_print_bits(t_uint octets);

// operand
int				nand(int a, int b);

// setters
void			turn_off_bit(int *ptr, int pos);
void			turn_off_bits(int *ptr, int start_pos, int length);
void			turn_on_bit(int *ptr, int pos);
void			turn_on_bits(int *ptr, int start_pos, int length);

// getters
int				get_bit(int value, int pos);
int				get_bit_value(int value, int pos);
int				get_bits(int value, int pos, int length);

/*
 *			char verification
 */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_iswhitespace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_ishex(char c);
int				ft_ischarset(char c, const char *charset);
/*
 *			string verification
 */
int				ft_only_alnum(char *str);
int				ft_only_alpha(char *str);
int				ft_only_ascii(char *str);
int				ft_only_digit(char *str);
int				ft_only_print(char *str);
int				ft_only_whitespace(char *str);
int				ft_onlyhex(char *str);
int				ft_only_charset(char *str, const char *charset);
/*
 *			string manip ajouter strsiteri
 */
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t siz);
size_t			ft_strlcpy(char *dst, const char *src, size_t siz);
int				ft_atoi(const char *nptr);
double			ft_atol(const char *nptr);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, t_uint n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strfjoin(char *src, char *dest);
char			*ft_str_add_char(char *str, char c);
char			*ft_remove_charset(char *str, const char *charset);
char			*ft_remove_substring(char *str, const char *dest);
/*int				ft_count_words(char *str, char c);*/
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
char			*ft_xtoa(unsigned long nbr, char type);
char			*ft_ltoa(long int n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strcasestr(char *str, char *to_find);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strrev(char *str);
char			*ft_cut(char from, char *str, int l);
void			ft_lowerise(char **ptr_s);
/*
 *			tab string manip
 */
int				ft_strslen(char **strs);
char			**ft_strsdup(char **strs);
char			**ft_split(const char *str, char c);
char			*ft_unsplit(char **strs, char c);
char			*ft_unsplit_skip(char **strs, char c, int k);
void			free_strs(char **strs);
void			ft_free_instrs(char **tab);
char			**ft_strsfadd(char **src, char *add);
char			**ft_strsfjoin(char **s1, char **s2);
void			ft_print_strs(char **strs);
/*
 *			memory manip
 */
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
/*
 *			int verification
 */
int				ft_abs(int nb);
int				ft_isprime(int nb);
int				ft_next_prime(int nb);
int				ft_min(int nb1, int nb2);
int				ft_max(int nb1, int nb2);
/*
 *			int size
 */
int				ft_intlen(unsigned int nb, char type);
int				ft_lintlen(long unsigned int nb, char type);
int				ft_xlen(unsigned long nbr);
/*
 *			int tab manip
 */
int				*ft_range(int min, int max);
int				*ft_rrange(int start, int end);
int				*ft_mintab(int *tab, unsigned int size);
int				*ft_maxtab(int *tab, unsigned int size);
void			ft_swap(int *a, int *b);
void			ft_quicksort(int *tab, int length);
void			ft_free_2d_int(int **tab, int y);

/*
 *			put func (return how much char was writen)
 */
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putendl(char *s);
int				ft_putnbr(int nb);
int				ft_putuint(unsigned int nb);
int				ft_puthex(unsigned int nbr, char type);
int				ft_putptr(unsigned long nbr);
int				ft_putlong(long int nb);

/*
 *			put in file descriptor or stream
 */
int				ft_putchar_fd(int fd, char c);
int				ft_putstr_fd(int fd, char *s);
int				ft_putendl_fd(int fd, char *s);
int				ft_putnbr_fd(int fd, int n);
int				ft_putuint_fd(int fd, unsigned int nb);
int				ft_puthex_fd(int fd, unsigned int nbr, char type);
int				ft_putptr_fd(int fd, unsigned long nbr);
int				ft_putlong_fd(int fd, long int nb);
/*
 *			FT_PRINTF et FT_DPRINTF
 */
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);

/*
 *			list manip
 */
// simple list
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstremove_if(t_list **head, void *ref, int (*cmp)(void *, void *, size_t), void (*del)(void *));
t_list			*ft_lstfind_middle(t_list **head);
t_list			*lst_merge_sort(t_list *head, int (*compare)(void *, void *));
// double list
t_dlist			*ft_dlstnew(void *content);
int				ft_dlstsize(t_dlist *lst);
void			ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void			ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void			ft_dlstdelone(t_dlist *lst, void (*del)(void *));
t_dlist			*ft_dlstlast(t_dlist *lst);
void			ft_dlstclear(t_dlist **lst, void (*del)(void *));
t_dlist			*ft_dlstmap(t_dlist *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_dlstiter(t_dlist *lst, void (*f)(void *));
// void			ft_dlstremove_if(t_dlist **head, void *ref, int (*cmp)());
t_dlist			*ft_dlstfind_middle(t_dlist **head);

/*
 *			Garbage Collector
*/
t_gc			*init_gc(void);
void			*ft_gcalloc(t_gc **head, t_uint size);
void			*ft_gc_addnode(t_dlist **head, void *ptr);
void			ft_clear_gc(t_gc **head);
char			**ft_add_strs_gc(t_gc **head, char **strs);

int				**ft_1d_to_2d_int(t_gc **gc, const int *tab,
					int rows, int cols);


/*
*		  GNL
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strjoin_gnl(char *s1, char *s2);
int		found_newline(char *str);
char	*get_next_line(int fd);
void	close_gnl(int fd);


#endif
