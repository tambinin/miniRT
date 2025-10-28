/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:42:43 by candriam          #+#    #+#             */
/*   Updated: 2024/07/14 11:21:14 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *rest);
char	*extract_first_line(char *str);
char	*extract_rest_line(char *rest);
char	*ft_strdup_gnl(char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *rest, char *buffer);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
size_t	ft_strlen_gnl(char *str);

#endif
