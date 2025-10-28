/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:58:24 by candriam          #+#    #+#             */
/*   Updated: 2024/07/15 17:56:09 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (ft_strchr(set, s1[first]) && first < last)
		first++;
	if (last == 0 || first == last)
		return (ft_strdup(""));
	last--;
	while (ft_strchr(set, s1[last]) && last > first)
		last--;
	str = malloc(last - first + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[first], last - first + 2);
	return (str);
}

char	*trim_line(const char *line)
{
	char	*trimmed;
	size_t	len;

	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' '
			|| line[len - 1] == '\t' || line[len - 1] == '\n'))
		len--;
	trimmed = ft_substr(line, 0, len);
	return (trimmed);
}
