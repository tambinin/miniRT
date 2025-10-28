/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uphexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:34 by candriam          #+#    #+#             */
/*   Updated: 2024/12/28 10:31:23 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int	ft_print_uphexa(unsigned int nb)
{
	unsigned int	result;
	char			*base;

	base = "0123456789ABCDEF";
	result = 0;
	if (nb >= 16)
	{
		result += ft_print_uphexa(nb / 16);
		result += ft_print_uphexa(nb % 16);
	}
	else
		result += ft_print_char(base[nb % 16]);
	return (result);
}
