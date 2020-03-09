/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2020/03/09 16:39:00 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

# define CONVERTERS "cspdiuxX%"
# define FLAGS "-0.*"

# define HEXA "0123456789abcdef"
# define HEXACAPS "0123456789ABCDEF"

typedef struct	s_flags
{
	char	conv;
	size_t	zero_pad;
	size_t	left_pad;
	size_t	precision;
}				t_flags;

int				ft_printf(const char *format, ...);

char			*print_char(va_list ap);
char			*print_string(va_list ap);
char			*print_pointer(va_list ap);
//char			*print_decimal(t_flags flags, va_list ap);
char			*print_integer(t_flags flags, va_list ap);
char			*print_uinteger(t_flags flags, va_list ap);
char			*print_uhexint(t_flags flags, va_list ap);
char			*print_uhexint_upcase(t_flags flags, va_list ap);
char			*print_percent(void);

int				freeup(t_list **print_sgmt, va_list *ap);
void			print(void *s);
char			is_converter(char c);
char			is_flag(char c);
void			init_flags(t_flags *flags);

char			parse_flag(t_flags *flags, char **str, char c, va_list *ap);
char			*convert(t_flags flags, va_list ap);

char			*tobase(size_t n, bool caps, int basesize);
char			*pad_free(char *str, size_t n, char blankchar, bool alignleft);
char			*autopad_free(char *str, t_flags flags);

#endif
