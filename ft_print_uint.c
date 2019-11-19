/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:59:46 by badam             #+#    #+#             */
/*   Updated: 2019/11/19 02:15:22 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_print_uint(unsigned int n)
{
	long	nb;
	long	suppowten;

	suppowten = 1;
	nb = (long)n;
	while (suppowten < nb)
		suppowten *= 10;
	if (suppowten <= 1 && !ft_putchar('0' + nb))
			return (0);
	else
		while (suppowten > 1)
			if (!ft_putchar('0' + ((nb / (suppowten /= 10)) % 10)))
				return (0);
	return (1);
}
