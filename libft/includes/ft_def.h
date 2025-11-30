/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:12:12 by benjamsc          #+#    #+#             */
/*   Updated: 2025/09/07 06:38:01 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H


# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define ORANGE "\033[0;91m"
# define PURPLE "\033[0;95m"
# define DARK_ORANGE "\033[0;33m"
# define PINK "\033[0;95m"
# define TEAL "\033[0;96m"
# define GRAY "\033[0;90m"

# define START 'S'
# define END 'E'

# define SIMPLE 's'
# define DOUBLE 'd'

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MAJ_HEX 'X'
# define MIN_HEX 'x'

# define PI 3.14159265359

typedef unsigned char	t_byte;

typedef unsigned int	t_uint;

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

typedef unsigned long	t_ulong;
typedef unsigned long	t_uintptr;
typedef unsigned int	t_uint;

typedef t_dlist			t_gc;

#endif
