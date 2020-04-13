/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:36:09 by badam             #+#    #+#             */
/*   Updated: 2020/04/13 16:46:38 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	add_string(char **str, t_list **print_lst, size_t *print_len)
{
	size_t		size;
	char		*strcpy;
	char		*content;
	t_list		*elem;
	t_segment	*sgmt;

	size = 0;
	strcpy = *str;
	while (*strcpy && *strcpy != '%' && strcpy++)
		size++;
	if (!(content = malloc((size + 1) * sizeof(char))))
		return (0);
	ft_memcpy((void*)content, (void*)*str, size);
	content[size] = '\0';
	sgmt = malloc_segment(content, size);
	if (!sgmt || !(elem = ft_lstnew(sgmt)))
	{
		free(sgmt);
		free(content);
		return (0);
	}
	ft_lstadd_back(print_lst, elem);
	*str += size;
	*print_len += size;
	return (1);
}

static int	add_convert(char **str, va_list *ap, t_list **print_sgmt,
		size_t *print_len)
{
	t_segment	content;
	t_list		*elem;
	t_segment	*sgmt;
	t_flags		flags;

	ft_memset(&flags, 0, sizeof(flags));
	while (**str && parse_flag(&flags, str, **str, ap))
		(*str)++;
	repair_flags(&flags);
	content = convert(flags, *ap);
	if (!(content.content))
		return (0);
	sgmt = dupli_segment(content);
	if (!sgmt || !(elem = ft_lstnew(sgmt)))
	{
		free(sgmt);
		free(content.content);
		return (0);
	}
	ft_lstadd_back(print_sgmt, elem);
	*print_len += sgmt->length;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*formatcpy;
	size_t	print_len;
	t_list	*print_lst;

	if (!format)
		return (-1);
	formatcpy = (char*)format;
	print_len = 0;
	print_lst = 0;
	va_start(ap, format);
	while (*formatcpy)
	{
		if (*formatcpy == '%' && ++formatcpy)
		{
			if (!add_convert(&formatcpy, &ap, &print_lst, &print_len))
				return (freeup(&print_lst, &ap));
		}
		else if (!add_string(&formatcpy, &print_lst, &print_len))
			return (freeup(&print_lst, &ap));
	}
	ft_lstiter(print_lst, &print);
	freeup(&print_lst, &ap);
	return (print_len);
}
