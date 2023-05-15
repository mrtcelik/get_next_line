/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:45:54 by mucelik           #+#    #+#             */
/*   Updated: 2023/05/13 15:31:44 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//get_next_line.c
char	*get_next_line(int fd);
char	*put_line(int fd, char *line);
char	*newlinedenonce(char *line);
char	*newlinedensonra(char *line);

//get_next_line_utils.c
char	*ft_strjoin(char *d_line, char *buff);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);

#endif
