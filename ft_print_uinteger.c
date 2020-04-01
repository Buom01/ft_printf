/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:32:43 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 04:39:40 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_uitoa(unsigned int n)
{
	unsigned int	ncpy;
	size_t			len;
	char			*str;

	len = 2;
	ncpy = n;
	while (ncpy / 10)
	{
		ncpy /= 10;
		len++;
	}
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	str[0] = '-';
	while (len > 0)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

char		*print_uinteger(t_flags flags, va_list ap)
{
	int	n;

	n = va_arg(ap, unsigned int);
	if (!n && flags.explicit_precision)
		return (autopad_free(ft_strdup(""), flags));
	return (autopad_free(ft_uitoa(n), flags));
}
