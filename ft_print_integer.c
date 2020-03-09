/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:32:43 by badam             #+#    #+#             */
/*   Updated: 2020/03/09 23:54:54 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_integer(t_flags flags, va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	if (!n && flags.explicit_precision)
		return ft_strdup("");
	return (autopad_free(ft_itoa(n), flags));
}
