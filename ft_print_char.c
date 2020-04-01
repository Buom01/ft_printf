/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 05:07:33 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_char(t_flags flags, va_list ap)
{
	char	*sgmt;

	if (!(sgmt = malloc(2 * sizeof(char))))
		return (NULL);
	sgmt[0] = va_arg(ap, int);
	sgmt[1] = '\0';
	return (autopad_free(sgmt, flags));
}
