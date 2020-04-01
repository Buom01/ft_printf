/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:32:43 by badam             #+#    #+#             */
/*   Updated: 2020/04/01 22:40:20 by badam            ###   ########.fr       */
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

t_segment	print_uinteger(t_flags flags, va_list ap)
{
	unsigned int	n;
	t_segment		sgmt;

	n = va_arg(ap, unsigned int);
	if (!n && flags.explicit_precision)
	{
		sgmt.content = ft_strdup("");
		sgmt.length = 0;
	}
	else
	{
		sgmt.content = ft_uitoa(n);
		sgmt.length = ft_strlen(sgmt.content);
	}
	return (autopad_free(sgmt, flags));
}
