/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 03:36:46 by badam            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

char		*print_string(t_flags flags, va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	return (autopad_free(autotrunc(ft_strdup(str), flags), flags));
}
