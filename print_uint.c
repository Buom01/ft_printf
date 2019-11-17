/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:59:46 by badam             #+#    #+#             */
/*   Updated: 2019/11/17 06:32:26 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	print_uint(unsigned int n)
{
	long	nb;
	long	suppowten;

	suppowten = 1;
	nb = (long)n;
	while (suppowten < nb)
		suppowten *= 10;
	if (suppowten <= 1 && !putchar('0' + nb))
			return (0);
	else
		while (suppowten > 1)
			if (!putchar('0' + ((nb / (suppowten /= 10)) % 10)))
				return (0);
	return (1);
}
