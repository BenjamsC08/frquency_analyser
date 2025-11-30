/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:46:52 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/12 20:32:12 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
int		found_newline(char *str);

char	*get_next_line(int fd);

void	close_gnl(int fd);

#endif
