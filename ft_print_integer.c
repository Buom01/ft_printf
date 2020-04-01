/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:32:43 by badam             #+#    #+#             */
/*   Updated: 2020/04/01 22:39:50 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment	print_integer(t_flags flags, va_list ap)
{
	int			n;
	t_segment	sgmt;

	n = va_arg(ap, int);
	if (!n && flags.explicit_precision)
	{
		sgmt.content = ft_strdup("");
		sgmt.length = 0;
	}
	else
	{
		sgmt.content = ft_itoa(n);
		sgmt.length = ft_strlen(sgmt.content);
	}
	return (autopad_free(sgmt, flags));
}
