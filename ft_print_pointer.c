/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:23:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 04:08:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_pointer(va_list ap)
{
	char	*sgmt;
	char	*hex;
	void	*pointer;

	pointer = va_arg(ap, void*);
	if (!pointer)
		return (ft_strdup("(nil)"));
	hex = tobase((size_t)pointer, false, 16);
	sgmt = ft_strjoin("0x", hex);
	if (hex)
		free(hex);
	return (sgmt);
}
