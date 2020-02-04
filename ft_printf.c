/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:36:09 by badam             #+#    #+#             */
/*   Updated: 2020/02/04 20:26:48 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libftprintf.h"

static int	add_string(char str, size_t size)
{
	
}

static int	add_convert(char c, char *str, va_list *ap)
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
	size_t	print_len;
	size_t	format_len;

	if (!format)
		return (-1);
	formatcpy = (char*)format;
	print_len = 0;
	va_start(ap, format);
	while (*formatcpy)
	{
		if (*formatcpy == '%' && ++formatcpy)
		{
			formatcpy += add_convert(*(formatcpy), formatcpy, &ap);
			print_len += ft_strlen();
		}
		else
		{
			format_len = ...;
			add_string(formatcpy, format_len);
			formatcpy += format_len;
			print_len += format_len;
		}
	}
	va_end(ap);
	print_all();
	return (printed_char);
}
