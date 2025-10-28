/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:10:04 by candriam          #+#    #+#             */
/*   Updated: 2025/01/04 12:11:15 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*read_file(int fd, char *rest)
{
	int		n_read;
	char	*buffer;

	n_read = 1;
	buffer = (char *)ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr_gnl(buffer, '\n')) && n_read != 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1 || (!rest && n_read == 0))
			return (free(rest), free(buffer), NULL);
		buffer[n_read] = '\0';
		if (!rest)
			rest = ft_strdup_gnl(buffer);
		else
			rest = ft_strjoin_gnl(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*extract_first_line(char *rest)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (rest[len] != '\n' && rest[len] != '\0')
		len++;
	line = malloc(sizeof(char) * len + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extract_rest_line(char *rest)
{
	int		len;
	int		i;
	char	*buffer;

	len = 0;
	i = 0;
	if (!rest)
		return (NULL);
	while (rest[len] && rest[len] != '\n')
		len++;
	if (rest[len] == '\n')
		len += 1;
	buffer = malloc(sizeof(char) * ((ft_strlen_gnl(rest) - len) + 1));
	if (!buffer)
		return (NULL);
	while (rest[len])
		buffer[i++] = rest[len++];
	buffer[i] = '\0';
	free(rest);
	return (buffer);
}

static void	free_rest(char **rest)
{
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*lign;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_file(fd, rest);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	lign = extract_first_line(rest);
	if (!lign)
	{
		free_rest(&rest);
		return (NULL);
	}
	rest = extract_rest_line(rest);
	return (lign);
}
