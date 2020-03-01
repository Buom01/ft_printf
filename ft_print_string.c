/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/01 03:27:52 by badam            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

char		*print_string(va_list ap)
{
	char	*sgmt;
	char	*str;
	size_t	len;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	len = ft_strlen(str); 
	if (!(sgmt = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy((void*)sgmt, (void*)str, len);
	sgmt[len] = '\0';
	return (sgmt);
}
