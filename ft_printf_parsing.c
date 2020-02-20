/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:16:17 by badam             #+#    #+#             */
/*   Updated: 2020/02/20 06:34:12 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flags(t_flags *flags)
{
	flags->conv = '\0';
	flags->flags
}

char	parse_flag(t_flags *flags, char *str, char c)
{
	int	flag_index;

	if (!(flags->conv))
		return (flags->conv = c);
	if (flags->conv == '%')
		return (0);
	if (!is_flag(c))
		return (0);
	if (c == '-')
		flags->left = !(flags->zero_pad = FALSE);
	else if (c == '0')
		flags->zero_pad = !flags->left;
	else if (c == '.')
	
	else if (c == '*')

	return (1);
	// if it's a converter, should I replace flags->conv ?
}

char	*convert(t_flags *flags, va_list *ap, size_t *ai)
{
}
