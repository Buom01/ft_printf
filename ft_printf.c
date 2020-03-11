/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:36:09 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 04:01:39 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	add_string(char **str, t_list **print_sgmt, size_t *print_len)
{
	size_t	size;
	char	*strcpy;
	char	*content;
	t_list	*sgmt;

	size = 0;
	strcpy = *str;
	while (*strcpy && *strcpy != '%' && strcpy++)
		size++;
	if (!(content = malloc((size + 1) * sizeof(char))))
		return (0);
	ft_memcpy((void*)content, (void*)*str, size);
	content[size] = '\0';
	if (!(sgmt = ft_lstnew(content)))
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(print_sgmt, sgmt);
	*str += size;
	*print_len += size;
	return (1);
}

static int	add_convert(char **str, va_list *ap, t_list **print_sgmt,
		size_t *print_len)
{
	char	*content;
	t_list	*sgmt;
	t_flags	flags;

	init_flags(&flags);
	while (**str && parse_flag(&flags, str, **str, ap))
		(*str)++;
	if (!(content = convert(flags, *ap)))
		return (0);
	if (!(sgmt = ft_lstnew(content)))
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(print_sgmt, sgmt);
	*print_len += ft_strlen(content);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*formatcpy;
	size_t	print_len;
	t_list	*print_sgmt;

	if (!format)
		return (-1);
	formatcpy = (char*)format;
	print_len = 0;
	print_sgmt = 0;
	va_start(ap, format);
	while (*formatcpy)
	{
		if (*formatcpy == '%' && ++formatcpy)
		{
			if (!add_convert(&formatcpy, &ap, &print_sgmt, &print_len))
				return (freeup(&print_sgmt, &ap));
		}
		else if (!add_string(&formatcpy, &print_sgmt, &print_len))
			return (freeup(&print_sgmt, &ap));
	}
	ft_lstiter(print_sgmt, &print);
	freeup(&print_sgmt, &ap);
	return (print_len);
}
