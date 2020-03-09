/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:16:17 by badam             #+#    #+#             */
/*   Updated: 2020/03/10 00:02:45 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	parse_pad(char **str)
{
	int	n;

	(*str)++;
	n = 0;
	while (ft_isdigit(**str))
	{
		n *= 10;
		n += **str - '0';
		(*str)++;
	}
	(*str)--;
	return (n);
}

static int	parse_precision(char **str, va_list *ap)
{
	int	n;

	(*str)++;
	if (**str == '*')
	{
		(*str)++;
		return (va_arg(*ap, int));
	}
	else if (ft_isdigit(**str))
	{
		n = 0;
		while (ft_isdigit(**str))
		{
			n *= 10;
			n += **str - '0';
			(*str)++;
		}
		(*str)--;
		return (n);
	}
	else
		return (0);
}

char		parse_flag(t_flags *flags, char **str, char c, va_list *ap)
{
	if (is_converter(c))
		return (flags->conv = c) && (*str)++ && false;
	if (!is_flag(c))
		return (is_converter(c));
	if (c == '-')
		flags->left_pad = parse_pad(str);
	else if (c == '0')
		flags->zero_pad = parse_pad(str);
	else if (c == '.')
	{
		flags->precision = parse_precision(str, ap);
		flags->explicit_precision = true;
	}

	return (1);
}

char		*convert(t_flags flags, va_list ap)
{
	if (flags.conv == 'c')
		return (print_char(ap));
	else if (flags.conv == 's')
		return (print_string(ap));
	else if (flags.conv == 'p')
		return (print_pointer(ap));
	else if (flags.conv == 'd')
		return (print_integer(flags, ap));
	else if (flags.conv == 'i')
		return (print_integer(flags, ap));
	else if (flags.conv == 'u')
		return (print_uinteger(flags, ap));
	else if (flags.conv == 'x')
		return (print_uhexint(flags, ap));
	else if (flags.conv == 'X')
		return (print_uhexint_upcase(flags, ap));
	return (print_percent());
}
