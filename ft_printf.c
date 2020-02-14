/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:36:09 by badam             #+#    #+#             */
/*   Updated: 2020/02/14 05:35:14 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

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
	ft_memcpy(content, *str, size);
	content[size] = '\0';
	if (!(sgmt = ft_lstnew(content)))
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(print_sgmt, sgmt);
	*str += size;
	*print_len += size;
	return (size);
}

static int	add_convert(char *str, va_list *ap, t_list **print_sgmt)
{
	(void)str;
	(void)ap;
	(void)print_sgmt;
	return (0);
	/*
	t_conv	convertion;
	char	*strcpy;

	strcpy = str;
	if (is_converter(*strcpy))
		t_conv.type = *str;
	else if (is_flag(*strcpy)) // review it
	{

	}
	return ((c == 'i') ? ft_print_int(va_arg(*ap, int)) :
			(c == 'u') ? ft_print_uint(va_arg(*ap, unsigned int)) :
			(c == 'l') ? ft_flag_long(*ap, *(str + 1)) :
			0);
	*/
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
	print_sgmt = NULL;
	va_start(ap, format);
	while (*formatcpy)
	{
		if (*formatcpy == '%' && ++formatcpy)
		{
			if (!(formatcpy += add_convert(formatcpy, &ap, &print_sgmt)))
				return freeup(&print_sgmt, &ap);
			print_len += ft_strlen(ft_lstlast(print_sgmt)->content);
		}
		else
			if (!add_string(&formatcpy, &print_sgmt, &print_len))
				return freeup(&print_sgmt, &ap);
	}
	ft_lstiter(print_sgmt, &print);
	freeup(&print_sgmt, &ap);
	return (print_len);
}
