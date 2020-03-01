/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/01 03:05:14 by badam            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

char		*print_char(va_list ap)
{
	char	*sgmt;

	if (!(sgmt = malloc(2 * sizeof(char))))
		return (NULL);
	sgmt[0] = va_arg(ap, int);
	sgmt[1] = '\0';
	return (sgmt);
}
