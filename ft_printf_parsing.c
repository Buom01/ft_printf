/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:16:17 by badam             #+#    #+#             */
/*   Updated: 2020/02/26 22:33:27 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		init_flags(t_flags *flags)
{
	flags->conv = '\0';
	flags->zero_pad = false;
	flags->left = false;
	flags->precision = 0;
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
		return (n);
	}
	else
		return (0);
}

char		parse_flag(t_flags *flags, char **str, char c, va_list *ap)
{
	int	flag_index;

	if (!(flags->conv))
		return (flags->conv = c);
	if (flags->conv == '%')
		return (0);
	if (!is_flag(c))
		return (0);
	if (c == '-')
		flags->left = !(flags->zero_pad = false);
	else if (c == '0')
		flags->zero_pad = !flags->left;
	else if (c == '.')
		flags->precision = parse_precision(str, ap);

	return (1);
	// if it's a converter, should I replace flags->conv ?
}

char		*convert(t_flags flags, va_list *ap)
{
	if (flags.conv == 'c')
		return (print_char(flags, ap));
	else if (flags.conv == 's')
		return (print_string(flags, ap));
	else if (flags.conv == 'p')
		return (print_pointer(flags, ap));
	else if (flags.conv == 'd')
		return (print_decimal(flags, ap));
	else if (flags.conv == 'i')
		return (print_integer(flags, ap));
	else if (flags.conv == 'u')
		return (print_uinteger(flags, ap));
	else if (flags.conv == 'x')
		return (print_uhexint(flags, ap));
	else if (flags.conv == 'X')
		return (print_uhexint_upcase(flags, ap));
	else if (flags.conv == '%')
		return (print_percent(flags, ap));
	
	return (NULL);  // What if no conv (or unknown) is provided ?
}
