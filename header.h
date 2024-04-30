/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:36:37 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/04/30 19:58:18 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*read_a_line(int fd, char **line, char **rmd);
char	*join_the_buf(int fd, char *line, ssize_t *b_len);
ssize_t	newline_seeker(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, ssize_t blen);
void	*ft_memcpy(void *dst, void *src, size_t n);

#endif
