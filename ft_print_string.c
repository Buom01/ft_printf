/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/12 17:29:49 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment		print_string(t_flags flags, va_list ap)
{
	char		*str;
	t_segment	sgmt;
	
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	sgmt.content = ft_strdup(str);
	sgmt.length = ft_strlen(str);
	return (autopad_free(autotrunc(sgmt, flags), flags));
}
