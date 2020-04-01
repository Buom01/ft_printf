/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/01 22:35:00 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment	print_char(t_flags flags, va_list ap)
{
	t_segment	sgmt;

	if (!(sgmt.content = malloc(2 * sizeof(char))))
	{
		sgmt.content = NULL;
		return (sgmt);
	}
	sgmt.content[0] = va_arg(ap, int);
	sgmt.content[1] = '\0';
	sgmt.length = 1;
	return (autopad_free(sgmt, flags));
}
