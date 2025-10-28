/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:54:45 by candriam          #+#    #+#             */
/*   Updated: 2025/01/24 10:05:02 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	space_sign_process(const char **nptr)
{
	while (**nptr == 32 || (**nptr >= 9 && **nptr <= 13))
		(*nptr)++;
	if (**nptr == '-')
	{
		(*nptr)++;
		return (-1);
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = space_sign_process(&nptr);
	while (ft_isdigit(*nptr))
		nb = (nb * 10) + (*nptr++ - 48);
	return (nb * sign);
}

static double	atof_process(const char *nptr)
{
	double	nb;
	double	divisor;

	nb = 0.0;
	divisor = 0.1;
	if (*nptr == '.')
	{
		nptr++;
		while (ft_isdigit(*nptr))
		{
			nb = nb + (*nptr - 48) * divisor;
			divisor *= 0.1;
			nptr++;
		}
	}
	return (nb);
}

double	ft_atof(const char *nptr)
{
	double	nb;
	int		sign;

	nb = 0.0;
	sign = space_sign_process(&nptr);
	while (*nptr && *nptr != '.')
	{
		if (ft_isdigit(*nptr))
			nb = (nb * 10) + (*nptr++ - 48);
		else
			return (nb * sign);
	}
	nb = nb + atof_process(nptr);
	return (nb * sign);
}
