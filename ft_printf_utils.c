/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:52:16 by badam             #+#    #+#             */
/*   Updated: 2020/02/14 00:49:53 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

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
		write ((int)stdout, (const void*)s, len);
}

char	is_converter(char c)
{
	return (c == 'i' || c == 'u');
}

char	is_flag(char c)
{
	return (c == 'l' || c == 'l');
}
