/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:53:23 by badam             #+#    #+#             */
/*   Updated: 2019/11/17 06:30:40 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	print_int(int n)
{
	int		positive;
	long	posinb;
	long	suppowten;

	suppowten = 1;
	positive = (n >= 0);
	posinb = positive ? (long)n : (-1 * (long)n);
	if (!positive && !putchar('-'))
		return (0);
	while (suppowten < posinb)
		suppowten *= 10;
	if (suppowten <= 1 && !putchar('0' + posinb))
			return (0);
	else
		while (suppowten > 1)
			if (!putchar('0' + ((posinb / (suppowten /= 10)) % 10)))
				return (0);
	return (1);
}
