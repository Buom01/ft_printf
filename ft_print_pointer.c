/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/02 16:56:05 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment	print_pointer(t_flags flags, va_list ap)
{
	t_segment	sgmt;
	char		*tmp;
	void		*pointer;

	pointer = va_arg(ap, void*);
	if (pointer)
		sgmt.content = tobase((size_t)pointer, false, 16);
	else
	{
		sgmt.content = ft_strdup("(nil)");
		sgmt.length = 5;
		return (sgmt);
	}
	sgmt.length = ft_strlen(sgmt.content);
	if (flags.precision)
	{
		sgmt = (pad_free(sgmt, flags.precision, '0', false));
	}
	tmp = sgmt.content;
	sgmt.content = ft_strjoin("0x", tmp);
	sgmt.length += 2;
	free(tmp);
	sgmt = autopad_free(sgmt, flags);
	return (sgmt);
}
