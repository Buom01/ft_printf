/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/01 22:38:45 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_segment	print_hexa(t_flags flags, unsigned int n, bool caps)
{
	t_segment	sgmt;

	if (!n && flags.explicit_precision)
	{
		sgmt.content = ft_strdup("");
		sgmt.length = 0;
	}
	else
	{
		sgmt.content = tobase(n, caps, 16);
		sgmt.length = ft_strlen(sgmt.content);
	}
	return (autopad_free(sgmt, flags));
}

t_segment			print_uhexint(t_flags flags, va_list ap)
{
	return (print_hexa(flags, va_arg(ap, unsigned int), false));
}

t_segment			print_uhexint_upcase(t_flags flags, va_list ap)
{
	return (print_hexa(flags, va_arg(ap, unsigned int), true));
}
