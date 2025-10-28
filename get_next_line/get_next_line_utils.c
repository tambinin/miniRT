/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:19:10 by candriam          #+#    #+#             */
/*   Updated: 2024/03/29 10:27:46 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin_gnl(char *rest, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;

	if (!rest && !buffer)
		return (NULL);
	l1 = ft_strlen_gnl(rest);
	l2 = ft_strlen_gnl(buffer);
	str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		str[i] = rest[i];
		i++;
	}
	free(rest);
	j = 0;
	while (j < l2)
		str[i++] = buffer[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup_gnl(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!(dest))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = nmemb * size;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	ptr[i] = '\0';
	return ((void *)ptr);
}
