/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhexint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/04 20:02:08 by badam            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

static char	*print_hexa(t_flags flags, unsigned int n, bool caps)
{
	return (pad_zero_free(tobase(n, caps, 16), flags.precision));
}

char		*print_uhexint(t_flags flags, va_list ap)
{
	return (print_hexa(flags, va_arg(ap, unsigned int), false));
}

char		*print_uhexint_upcase(t_flags flags, va_list ap)
{
	return (print_hexa(flags, va_arg(ap, unsigned int), true));
}
