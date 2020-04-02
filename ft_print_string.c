/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/02 18:03:00 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment		print_string(t_flags flags, va_list ap)
{
	char		*str;
	t_segment	sgmt;
	
	if (!(str = va_arg(ap, char*)))
		str = (flags.explicit_precision && flags.precision < 6) ? "" : "(null)";
	sgmt.content = ft_strdup(str);
	sgmt.length = ft_strlen(str);
	if (flags.zero_pad)
		flags.right_pad = flags.zero_pad;
	return (autopad_free(autotrunc(sgmt, flags), flags));
}
