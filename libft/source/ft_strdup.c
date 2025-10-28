/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:00:56 by candriam          #+#    #+#             */
/*   Updated: 2024/08/25 16:09:43 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
