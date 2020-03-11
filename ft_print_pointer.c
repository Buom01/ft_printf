/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 05:01:52 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_pointer(t_flags flags, va_list ap)
{
	char	*sgmt;
	char	*hex;
	void	*pointer;

	pointer = va_arg(ap, void*);
	if (!pointer && flags.explicit_precision)
		hex = ft_strdup("");
	else
		hex = tobase((size_t)pointer, false, 16);
	if (flags.precision)
		hex = (pad_free(hex, flags.precision, '0', false));
	sgmt = autopad_free(ft_strjoin("0x", hex), flags);
	if (hex)
		free(hex);
	return (sgmt);
}
