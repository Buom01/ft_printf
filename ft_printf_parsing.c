/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:16:17 by badam             #+#    #+#             */
/*   Updated: 2020/04/12 17:24:17 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	parse_pad(char **str, va_list *ap)
{
	int	n;

	(*str)++;
	n = 0;
	if (**str == '*')
		return (va_arg(*ap, int));
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
		return (va_arg(*ap, int));
	else
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
}

void		repair_flags(t_flags *flags)
{
	if (flags->left_pad < 0)
		flags->left_pad = -(flags->left_pad);
	if (flags->right_pad < 0)
	{
		if (flags->left_pad < -(flags->right_pad))
			flags->left_pad = -(flags->right_pad);
		flags->right_pad = 0;
	}
	if (flags->zero_pad < 0)
	{
		if (!flags->left_pad)
			flags->left_pad = -(flags->zero_pad);
		flags->zero_pad = 0;
	}
	if (flags->precision < 0)
	{
		flags->precision = 0;
		flags->explicit_precision = false;
	}
}

char		parse_flag(t_flags *flags, char **str, char c, va_list *ap)
{
	if (is_converter(c))
		return (flags->conv = c) && (*str)++ && false;
	if (!is_flag(c) && !ft_isdigit(c))
		return (is_converter(c));
	if (c == '-')
		flags->left_pad = parse_pad(str, ap);
	else if (c == '0')
		flags->zero_pad = parse_pad(str, ap);
	else if (ft_isdigit(c) && (*str)--)
		flags->right_pad = parse_pad(str, ap);
	else if (c == '.')
	{
		flags->precision = parse_precision(str, ap);
		flags->explicit_precision = true;
	}
	else if (c == '*')
		flags->right_pad = va_arg(*ap, int);
	return (1);
}

t_segment	convert(t_flags flags, va_list ap)
{
	if (flags.conv == 'c')
		return (print_char(flags, ap));
	else if (flags.conv == 's')
		return (print_string(flags, ap));
	else if (flags.conv == 'p')
		return (print_pointer(flags, ap));
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
	return (print_percent(flags));
}
