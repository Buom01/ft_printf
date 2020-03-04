/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:52:16 by badam             #+#    #+#             */
/*   Updated: 2020/03/04 18:38:33 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		freeup(t_list **print_sgmt, va_list *ap)
{
	ft_lstclear(print_sgmt, &free);
	va_end(*ap);
	return (0);
}

void	print(void *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen((char*)s);
	if (len)
		write (1, (const void*)s, len);
}

char	is_converter(char c)
{
	int	i;

	i = 0;
	while (CONVERTERS[i])
		if (CONVERTERS[i++] == c)
			return (1);
	return (0);
}

char	is_flag(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
		if (FLAGS[i++] == c)
			return (1);
	return (0);
}
