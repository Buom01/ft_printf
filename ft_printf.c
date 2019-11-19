/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:36:09 by badam             #+#    #+#             */
/*   Updated: 2019/11/19 06:36:12 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

static int	ft_printf_convert(char c, char *str, va_list *ap)
{
	return ((c == 'i') ? ft_print_int(va_arg(*ap, int)) :
			(c == 'u') ? ft_print_uint(va_arg(*ap, unsigned int)) :
			(c == 'l') ? ft_flag_long(*ap, *(str + 1)) :
			0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*formatcpy;
	int		printed_char;
	int		cnvt_printed_char;

	if (!format)
		return (-1);
	formatcpy = (char*)format;
	printed_char = 0;
	va_start(ap, format);
	while (*formatcpy)
	{
		if (*formatcpy == '%' && ++formatcpy)
		{
			cnvt_printed_char = ft_printf_convert(*(formatcpy), formatcpy, &ap);
			if (cnvt_printed_char < 0)
				return (-1);
			else
				printed_char += cnvt_printed_char;
		}
		else
		{
			if (++printed_char && write(1, formatcpy, 1) < 0)
				return (-1);
		}
		formatcpy++;
	}
	va_end(ap);
	return (printed_char);
}
