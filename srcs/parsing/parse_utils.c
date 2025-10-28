/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:48:26 by candriam          #+#    #+#             */
/*   Updated: 2025/01/24 14:57:52 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	is_norm(char *str)
{
	char	**xyz;
	float	v[3];
	float	res;
	int		i;

	if (check_coma(str, ',') != 2)
		return (false);
	xyz = ft_split(str, ',');
	if (!xyz)
		return (false);
	i = 0;
	res = 0;
	while (i < 3)
	{
		v[i] = ft_atof(xyz[i]);
		res += v[i] * v[i];
		i++;
	}
	ft_free_array(&xyz);
	return (res >= 0.999f && res <= 1.001f && res != 0);
}

bool	is_valid_pos(const char *str)
{
	char	**xyz;
	int		i;

	if (check_coma(str, ',') != 2)
		return (false);
	xyz = ft_split(str, ',');
	if (!xyz || ft_arr_len(xyz) != 3)
	{
		ft_free_array(&xyz);
		return (false);
	}
	i = 0;
	while (i < 3)
	{
		if (!is_valid_float(xyz[i]))
		{
			ft_free_array(&xyz);
			return (false);
		}
		i++;
	}
	ft_free_array(&xyz);
	return (true);
}

bool	is_valid_color(const char *str)
{
	char	**color;
	int		i;

	if (check_coma(str, ',') != 2)
		return (false);
	color = ft_split(str, ',');
	if (!color || ft_arr_len(color) != 3)
	{
		ft_free_array(&color);
		return (false);
	}
	i = 0;
	while (i < 3)
	{
		if (!is_valid_float(color[i]) || ft_atof(color[i]) < 0
			|| ft_atof(color[i]) > 255)
		{
			ft_free_array(&color);
			return (false);
		}
		i++;
	}
	ft_free_array(&color);
	return (true);
}

bool	is_valid_float(const char *str)
{
	int	is_dec;
	int	is_digit;

	if (str == NULL || *str == '\0')
		return (false);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	is_dec = 0;
	is_digit = 0;
	if (!check_float(str, &is_dec, &is_digit))
		return (false);
	return (true);
}

bool	check_float(const char *str, int *is_dec, int *is_digit)
{
	while (*str && ft_isdigit(*str))
	{
		*is_digit = 1;
		str++;
	}
	if (*str == '.')
	{
		*is_dec = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		str++;
	if (!*is_digit || (*is_dec && !ft_isdigit(*(str - 1))))
		return (false);
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (false);
	}
	return (true);
}
