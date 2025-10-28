/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:37:04 by candriam          #+#    #+#             */
/*   Updated: 2024/07/15 17:47:33 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

long	str_to_long(const char *nptr)
{
	int		pos;
	int		is_neg;
	long	data;

	pos = 0;
	is_neg = 1;
	data = 0;
	while (nptr[pos] == 32 || (nptr[pos] >= 9 && nptr[pos] <= 13))
		pos++;
	if (nptr[pos] == '-')
	{
		is_neg *= -1;
		pos++;
	}
	else if (nptr[pos] == '+')
		pos++;
	while (nptr[pos])
	{
		if (!(nptr[pos] >= 48 && nptr[pos] <= 57))
			return (2147483648);
		else
			data = data * 10 + (nptr[pos++] - 48);
	}
	return (is_neg * data);
}

const char	*skip_spaces(const char *nptr, int *sign)
{
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		*sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (nptr);
}

static double	extract_part(const char **nptr, double *divisor)
{
	double	fraction;

	fraction = 0.0;
	if (**nptr == '.')
	{
		(*nptr)++;
		while (ft_isdigit(**nptr))
		{
			fraction += (**nptr - 48) / *divisor;
			*divisor *= 10.0;
			(*nptr)++;
		}
	}
	return (fraction);
}

double	ft_strict_atof(const char *nptr)
{
	double	nb;
	double	fraction;
	double	divisor;
	int		is_negative;

	is_negative = 1;
	nb = 0.0;
	divisor = 10.0;
	nptr = skip_spaces(nptr, &is_negative);
	if (!ft_isdigit(*nptr))
	{
		return (0);
	}
	while (ft_isdigit(*nptr))
		nb = (nb * 10) + (*nptr++ - 48);
	fraction = extract_part(&nptr, &divisor);
	return (is_negative * (nb + fraction));
}
