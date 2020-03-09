/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:32:43 by badam             #+#    #+#             */
/*   Updated: 2020/03/09 16:47:25 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_uitoa(unsigned int n)
{
	unsigned int	ncpy;
	size_t			strlen;
	char			*str;

	strlen = 2;
	ncpy = n;
	while (ncpy / 10)
	{
		ncpy /= 10;
		strlen++;
	}
	if (!(str = malloc(sizeof(char) * strlen)))
		return (NULL);
	str[--strlen] = '\0';
	str[0] = '-';
	while (strlen > 0)
	{
		str[--strlen] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

char		*print_uinteger(t_flags flags, va_list ap)
{
	return (autopad_free(ft_uitoa(va_arg(ap, unsigned int)), flags));
}
