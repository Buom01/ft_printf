/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 00:25:18 by badam            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

char		*print_string(va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	return (ft_strdup(str));
}
